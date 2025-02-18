/*
    ______     ____  ____  ____  __ __    ____  ___  _________    ____  ___   _____ ______
   / ____/    / __ )/ __ \/ __ \/ //_/   / __ \/   |/_  __/   |  / __ )/   | / ___// ____/
  / __/______/ __  / / / / / / / ,<     / / / / /| | / / / /| | / __  / /| | \__ \/ __/   
 / /__/_____/ /_/ / /_/ / /_/ / /| |   / /_/ / ___ |/ / / ___ |/ /_/ / ___ |___/ / /___   
/_____/    /_____/\____/\____/_/ |_|  /_____/_/  |_/_/ /_/  |_/_____/_/  |_/____/_____/   
                                                                                          
*/
-- Author
INSERT INTO AUTHOR
VALUES ('AU0000001', 'Robert Martin', '5101 Washington St. Suite 2I, Gurnee, IL, 60031, USA');
INSERT INTO AUTHOR
VALUES ('AU0000002', 'Alan Beaulieu', NULL);
INSERT INTO AUTHOR
VALUES ('AU0000003', 'Anthony Molinaro', NULL);
INSERT INTO AUTHOR
VALUES ('AU0000004', 'Upom Malik', NULL);
INSERT INTO AUTHOR
VALUES ('AU0000005', 'Paul Dourish', NULL);
SELECT * FROM AUTHOR;

-- Publisher
INSERT INTO publisher
VALUES ('OReilly', NULL, NULL);
INSERT INTO publisher
VALUES ('Packt Publishing', NULL, NULL);
INSERT INTO publisher
VALUES ('The MIT Press', NULL, NULL);
INSERT INTO publisher
VALUES ('Prentice Hall', NULL, NULL);
SELECT * FROM PUBLISHER;

-- Book
INSERT INTO BOOK
VALUES ('0000000000001', 'Sparrow and Strawberry', '100000','Prentice Hall','AU0000004');
INSERT INTO BOOK
VALUES ('0000000000002', 'How to influence the people', '56000','OReilly','AU0000005');
INSERT INTO BOOK
VALUES ('0000000000003', 'Deep taking', '30000','OReilly','AU0000004');
INSERT INTO BOOK
VALUES ('0000000000004', 'Beginning', '49560','OReilly','AU0000003');
INSERT INTO BOOK
VALUES ('0000000000005', 'Flower', '126400','Packt Publishing','AU0000002');
INSERT INTO BOOK
VALUES ('0000000000006', 'Sun', '200900','Packt Publishing','AU0000001');
INSERT INTO BOOK
VALUES ('0000000000007', 'No SQL: The Shifting Materialities of Database Technology', '245504','The MIT Press','AU0000005');
SELECT * FROM BOOK;


-- EBOOK
INSERT INTO EBOOK
VALUES ('0000000000006', NULL);
INSERT INTO EBOOK
VALUES ('0000000000007', NULL);
SELECT * FROM EBOOK;

-- TRADITIONAL BOOK
INSERT INTO traditional_book
VALUES ('0000000000001','AVAILABLE');
INSERT INTO traditional_book
VALUES ('0000000000002','UNAVAILABLE');
INSERT INTO traditional_book
VALUES ('0000000000003','AVAILABLE');
INSERT INTO traditional_book
VALUES ('0000000000004','AVAILABLE');
INSERT INTO traditional_book
VALUES ('0000000000005','UNAVAILABLE');
SELECT * FROM TRADITIONAL_BOOK;

-- EMPLOYEE
INSERT INTO EMPLOYEE
VALUES ('000000001', 'John','Lenon');
INSERT INTO EMPLOYEE
VALUES ('000000002', 'Mike','Watzowski');
INSERT INTO EMPLOYEE
VALUES ('000000003', 'Shaco','Pinky');
INSERT INTO EMPLOYEE
VALUES ('000000004', 'Saborah','Johnson');
INSERT INTO EMPLOYEE
VALUES ('000000005', 'Anna','Bayes');
INSERT INTO EMPLOYEE
VALUES ('000000006', 'Kaisa','Howwy');
INSERT INTO EMPLOYEE
VALUES ('000000007', 'Elsa','Boskawa');
SELECT * FROM EMPLOYEE;

-- WAREHOUSE
INSERT INTO warehouse
VALUES ('WH 01',NULL,NULL,'000000001');
INSERT INTO warehouse
VALUES ('WH 02',NULL,NULL,'000000002');
INSERT INTO warehouse
VALUES ('WH 03',NULL,NULL,'000000003');
SELECT * FROM WAREHOUSE;

-- STOCKED IN
INSERT INTO stocked_in
VALUES ('0000000000001','WH 01',200);
INSERT INTO stocked_in
VALUES ('0000000000002','WH 02',100);
INSERT INTO stocked_in
VALUES ('0000000000003','WH 03',300);
INSERT INTO stocked_in
VALUES ('0000000000004','WH 01',0);
INSERT INTO stocked_in
VALUES ('0000000000005','WH 02',250);
SELECT * FROM STOCKED_IN;

-- CHECKS
INSERT INTO checks
VALUES ('0000000000002','000000001','WH 01',20,0);
INSERT INTO checks
VALUES ('0000000000005','000000001','WH 01',0,70);
INSERT INTO checks
VALUES ('0000000000002','000000004','WH 03',30,0);
INSERT INTO checks
VALUES ('0000000000002','000000002','WH 01',0,100);
INSERT INTO checks
VALUES ('0000000000001','000000003','WH 03',80,0);
SELECT * FROM CHECKS;

-- CUSTOMER
INSERT INTO customer
VALUES ('C00000001',NULL,NULL,NULL,NULL,'Nguyen','Pham');
INSERT INTO customer
VALUES ('C00000002',NULL,NULL,NULL,NULL,'Andree','Pham');
INSERT INTO customer
VALUES ('C00000003',NULL,NULL,NULL,NULL,'Hien','Tran');
INSERT INTO customer
VALUES ('C00000004',NULL,NULL,NULL,NULL,'Mina','Truong');
SELECT * FROM CUSTOMER;

-- CREDIT CARD
INSERT INTO credit_card
VALUES ('1231123112311231',NULL,'Nguyen','OCB',NULL,'C00000001');
INSERT INTO credit_card
VALUES ('1231123112311232',NULL,'Nguyen','BIDV',NULL,'C00000001');
INSERT INTO credit_card
VALUES ('2345234523452345',NULL,'Hien','OCB',NULL,'C00000003');
INSERT INTO credit_card
VALUES ('3456345634563456',NULL,'Andree','OCB',NULL,'C00000002');
INSERT INTO credit_card
VALUES ('4444444444444444',NULL,'Mina','ACB',NULL,'C00000004');
SELECT * FROM CREDIT_CARD;

-- SHIPPING METHOD
INSERT INTO shipping_method
VALUES ('S00000001',30000);
INSERT INTO shipping_method
VALUES ('S00000002',10000);
INSERT INTO shipping_method
VALUES ('S00000003',0);
INSERT INTO shipping_method
VALUES ('S00000004',0);
SELECT * FROM SHIPPING_METHOD;

-- ADDRESS METHOD
INSERT INTO address_method
VALUES ('S00000001','123 Nguyen Hue Street TP HCM');
INSERT INTO address_method
VALUES ('S00000002','66 Nguyen Van Con Street TP HCM');
SELECT *FROM ADDRESS_METHOD;

-- EMAIL METHOD
INSERT INTO email_method
VALUES ('S00000003','taitran_926@gmail.com');
INSERT INTO email_method
VALUES ('S00000004','nguythuong_11@gmail.com');
SELECT *FROM EMAIL_METHOD;

-- BOOK TRANSACTION
INSERT INTO book_transaction
VALUES ('C00000001','0000000000007','2020-11-22','WAITING',NULL,500000,'2020-11-26','S00000001');
INSERT INTO book_transaction
VALUES ('C00000002','0000000000006','2020-11-23','ERROR',NULL,240000,'2020-11-26','S00000002');
INSERT INTO book_transaction
VALUES ('C00000003','0000000000001','2020-11-29','ERROR',NULL,220000,'2020-11-30','S00000003');
INSERT INTO book_transaction
VALUES ('C00000004','0000000000003','2020-10-24','EXPORT',NULL,100000,'2020-11-26','S00000003');
INSERT INTO book_transaction
VALUES ('C00000002','0000000000004','2020-11-18','SUCCESS',NULL,50000,'2020-11-26','S00000004');
SELECT * FROM BOOK_TRANSACTION;

-- BOOK IN TRANSACTION
INSERT INTO book_in_transaction
VALUES ('C00000001','2020-11-22','0000000000005',2,'BUY');
INSERT INTO book_in_transaction
VALUES ('C00000001','2020-11-23','0000000000005',4,'BUY');
INSERT INTO book_in_transaction
VALUES ('C00000004','2020-10-24','0000000000002',1,'BORROW');
INSERT INTO book_in_transaction
VALUES ('C00000004','2020-10-24','0000000000001',4,'BUY');
INSERT INTO book_in_transaction
VALUES ('C00000003','2020-10-24','0000000000001',4,'BUY');
INSERT INTO book_in_transaction
VALUES ('C00000003','2020-11-29','0000000000006',12,'BORROW');
INSERT INTO book_in_transaction
VALUES ('C00000002','2020-11-23','0000000000006',25,'BORROW');
INSERT INTO book_in_transaction
VALUES ('C00000002','2020-11-18','0000000000006',2,'BUY');
SELECT * FROM BOOK_IN_TRANSACTION;

-- PAYMENT
INSERT INTO payment
VALUES ('P00000001','2020-11-22','UNPAID','C00000001');
INSERT INTO payment
VALUES ('P00000002','2020-11-23','PAID','C00000002');
INSERT INTO payment
VALUES ('P00000003','2020-11-29','PAID','C00000003');
INSERT INTO payment
VALUES ('P00000004','2020-10-24','PAID','C00000004');
INSERT INTO payment
VALUES ('P00000005','2020-11-18','PAID','C00000002');
SELECT * FROM PAYMENT;

-- TRANSFER
INSERT INTO TRANSFER
VALUES ('P00000001',NULL);
INSERT INTO TRANSFER
VALUES ('P00000004',NULL);
SELECT * FROM TRANSFER;

-- CREDIT PAYMENT
INSERT INTO credit_payment
VALUES ('P00000002','3456345634563456');
INSERT INTO credit_payment
VALUES ('P00000003','2345234523452345');
INSERT INTO credit_payment
VALUES ('P00000005','3456345634563456');
SELECT * FROM CREDIT_PAYMENT;

-- BOOK FIELD
INSERT INTO book_field
VALUES ('0000000000005','Van hoc');
INSERT INTO book_field
VALUES ('0000000000005','KHXH');
INSERT INTO book_field
VALUES ('0000000000007','Van hoc');
INSERT INTO book_field
VALUES ('0000000000007','KHTN');
INSERT INTO book_field
VALUES ('0000000000006','Lich su');
INSERT INTO book_field
VALUES ('0000000000006','Van hoc');
INSERT INTO book_field
VALUES ('0000000000004','Sinh hoc');
INSERT INTO book_field
VALUES ('0000000000003','Lich su');
INSERT INTO book_field
VALUES ('0000000000003','KHTN');
INSERT INTO book_field
VALUES ('0000000000005','Sinh hoc');
SELECT * FROM BOOK_FIELD;

-- BOOK KEYWORD
INSERT INTO book_keyword
VALUES ('0000000000001','chim');
INSERT INTO book_keyword
VALUES ('0000000000001','trai cay');
INSERT INTO book_keyword
VALUES ('0000000000002','anh huong');
INSERT INTO book_keyword
VALUES ('0000000000002','con nguoi');
INSERT INTO book_keyword
VALUES ('0000000000003','sau');
INSERT INTO book_keyword
VALUES ('0000000000003','ngon ngu');
INSERT INTO book_keyword
VALUES ('0000000000004','bat dau');
INSERT INTO book_keyword
VALUES ('0000000000005','giai thich');
INSERT INTO book_keyword
VALUES ('0000000000005','tu nhien');
INSERT INTO book_keyword
VALUES ('0000000000005','hoa');
INSERT INTO book_keyword
VALUES ('0000000000006','mat troi');
INSERT INTO book_keyword
VALUES ('0000000000006','truyen tranh');
INSERT INTO book_keyword
VALUES ('0000000000007','sql');
INSERT INTO book_keyword
VALUES ('0000000000007','database');
SELECT * FROM BOOK_KEYWORD;

-- BOOK PUBLISHED YEAR
INSERT INTO book_year_published
VALUES ('0000000000001',1999);
INSERT INTO book_year_published
VALUES ('0000000000001',2010);
INSERT INTO book_year_published
VALUES ('0000000000002',2010);
INSERT INTO book_year_published
VALUES ('0000000000002',2015);
INSERT INTO book_year_published
VALUES ('0000000000003',1999);
INSERT INTO book_year_published
VALUES ('0000000000004',2002);
INSERT INTO book_year_published
VALUES ('0000000000004',2015);
INSERT INTO book_year_published
VALUES ('0000000000005',2005);
INSERT INTO book_year_published
VALUES ('0000000000006',1989);
INSERT INTO book_year_published
VALUES ('0000000000007',2015);
INSERT INTO book_year_published
VALUES ('0000000000007',2016);
SELECT * FROM BOOK_YEAR_PUBLISHED;

-- WORK FOR
INSERT INTO work_for
VALUES ('OReilly','AU0000001',15000000,'IN HA NOI');
INSERT INTO work_for
VALUES ('Prentice Hall','AU0000004',30000000,'HOW TO CRUSH SOMEONE');
SELECT * FROM WORK_FOR;

-- BUY/BORROW
INSERT INTO buys_borrows
VALUES ('C00000002','0000000000004',2,'2020-10-24');
INSERT INTO buys_borrows
VALUES ('C00000003','0000000000005',3,'2020-10-25');
INSERT INTO buys_borrows
VALUES ('C00000001','0000000000003',5,'2020-10-20');
SELECT * FROM BUYS_BORROWS;

-- COD
INSERT INTO cod
VALUES ('P00000004','BEST EXPRESS');
INSERT INTO cod
VALUES ('P00000002','VIETELPOST');
SELECT * FROM COD;