-- i.1,2 Cập nhật thông tin về sách khi sách được xuất / nhập kho.
drop procedure if exists updateExImport;
delimiter //
create procedure updateExImport(WH varchar(100), EID int(9), Im_Qty int, Ex_Qty int, ISBN_up char(13), Date_im_ex Date)
begin
declare avail int;
insert into checks
values(ISBN_up, EID,WH, Im_Qty, Ex_Qty, Date_im_ex);
select AVAILABLE_QTY into avail
from stocked_in
where TRD_BOOK_ISBN = ISBN_up and WNAME = WH;
update stocked_in
set AVAILABLE_QTY = avail + Im_Qty-Ex_Qty
where TRD_BOOK_ISBN = ISBN_up and WNAME = WH;
end //
delimiter;

-- i.3 Cập nhật thông tin giao dịch khi giao dịch trực tuyến gặp sự cố.
drop procedure if exists updateTransaction;
delimiter //
create procedure updateTransaction(pdate datetime, id int(9), status_in varchar(50))
begin
declare status_1 varchar(50);
select trans_status into status_1 from book_transaction
where CID = id and purchased_date = pdate;
if status_1 = 'ERROR' then
update book_transaction
set trans_status = status_in, response_date = now()
where CID = id and purchased_date = pdate;
end if;
end //
delimiter;

-- i.4 Xem tất cả các sách tính theo ISBN được mua trong một ngày.
drop procedure if exists viewAllISBN;
delimiter //
create procedure viewAllISBN(dateneed date)
begin
select ISBN, TITLE from book
where book.ISBN in (select ISBN from book_in_transaction
					where date(PURCHASED_DATE) = dateneed);
end //
delimiter;

-- i.5 Xem tổng số sách tính theo mỗi ISBN được mua trong một ngày.
drop procedure if exists viewSumOfISBN;
delimiter //
create procedure viewSumOfISBN(dateneed date)
begin
select ISBN, sum(QTY) as sum_qty from book_in_transaction
where date(PURCHASED_DATE) = dateneed and TRANS_TYPE = 'BUY'
group by ISBN;
end //
delimiter;

-- i.6 Xem tổng số sách truyền thống tính theo mỗi ISBN được mua trong một ngày.
drop procedure if exists viewSumOfTradi;
delimiter //
create procedure viewSumOfTradi(dateneed date)
begin
select ISBN, sum(QTY) from book_in_transaction
where date(PURCHASED_DATE) = dateneed and TRANS_TYPE = 'BUY' and ISBN in (select ISBN from traditional_book)
group by ISBN;
end //
delimiter;

-- i.7 Xem tổng số sách điện tử được mua trong một ngày.
drop procedure if exists viewSumOfEbookBuy;
delimiter //
create procedure viewSumOfEbookBuy(dateneed date)
begin
select sum(Qty) from book_in_transaction
where date(PURCHASED_DATE) = dateneed and TRANS_TYPE = 'BUY' and ISBN in (select ISBN from ebook);
end //
delimiter;

-- i.8 Xem tổng số sách điện tử được thuê trong một ngày.
drop procedure if exists viewSumOfEbookBorrow;
delimiter //
create procedure viewSumOfEbookBorrow(dateneed date)
begin
select count(ISBN) from book_in_transaction
where date(PURCHASED_DATE) = dateneed and TRANS_TYPE = 'BORROW' and ISBN in (select ISBN from ebook);
end //
delimiter;
