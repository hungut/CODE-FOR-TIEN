DROP SCHEMA IF EXISTS EBOOKSTORE;
CREATE SCHEMA EBOOKSTORE;
USE EBOOKSTORE;

CREATE TABLE PUBLISHER (
	PNAME		VARCHAR(100),
	ADDRESS		VARCHAR(100),
	PHONE		CHAR(11),
	PRIMARY KEY (PNAME)
);

CREATE TABLE AUTHOR (
	ID		CHAR(9),
	ANAME 	VARCHAR(100) NOT NULL,
	ADDRESS	VARCHAR(100),
	PRIMARY KEY (ID)
);

CREATE TABLE BOOK(
	ISBN		CHAR(13),
	TITLE		VARCHAR(100) NOT NULL,
	PRICE		BIGINT NOT NULL,
	PUBLISHER_NAME VARCHAR(100) NOT NULL,
    AUTHOR_ID CHAR(9) NOT NULL,
	PRIMARY KEY (ISBN),
    FOREIGN KEY (PUBLISHER_NAME) REFERENCES PUBLISHER(PNAME),
    FOREIGN KEY (AUTHOR_ID) REFERENCES AUTHOR(ID)
);

CREATE TABLE WORK_FOR(
    PNAME VARCHAR(100),
    AUTHOR_ID CHAR(9),
    SALARY BIGINT,
    PROJECT_BOOK VARCHAR(100),
    PRIMARY KEY (PNAME, AUTHOR_ID),
    FOREIGN KEY (PNAME) REFERENCES PUBLISHER(PNAME) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (AUTHOR_ID) REFERENCES AUTHOR(ID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE EBOOK (
	ISBN 	CHAR(13) ,
	URL	VARCHAR(255),
	PRIMARY KEY (ISBN),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
    /*Syntax for foreign key ; on delete cascade: when parent delete--> child delete ,the similar with update  */
);
CREATE TABLE TRADITIONAL_BOOK (
	ISBN 	CHAR(13) ,
    BOOK_STATUS VARCHAR(30) CHECK (BOOK_STATUS IN ('AVAILABLE','UNAVAILABLE')),
	PRIMARY KEY (ISBN),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE EMPLOYEE (
	ID	CHAR(9),
	FNAME	VARCHAR(100) NOT NULL,
    LNAME	VARCHAR(100) NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE WAREHOUSE (
	WNAME		VARCHAR(100),
	PHONE		CHAR(11),
	ADDRESS 	VARCHAR(100),
    MANAGER_ID	CHAR(9) not null,
	PRIMARY KEY (WNAME),
    FOREIGN KEY (MANAGER_ID) REFERENCES EMPLOYEE(ID) ON DELETE CASCADE ON UPDATE CASCADE
    
);

CREATE TABLE STOCKED_IN (
	TRD_BOOK_ISBN	CHAR(13),
	WNAME	VARCHAR(100),
	AVAILABLE_QTY	INT,
	PRIMARY KEY (TRD_BOOK_ISBN,WNAME),
	FOREIGN KEY (TRD_BOOK_ISBN) REFERENCES TRADITIONAL_BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (WNAME) REFERENCES WAREHOUSE(WNAME) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BOOK_FIELD (
	ISBN	CHAR(13),
	BFIELD	VARCHAR(50),
	PRIMARY KEY (ISBN, BFIELD),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BOOK_KEYWORD (
	ISBN	CHAR(13),
	KEYWORD	VARCHAR(50),
	PRIMARY KEY (ISBN, KEYWORD),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BOOK_YEAR_PUBLISHED (
	ISBN	CHAR(13),
	PYEAR	YEAR,
	PRIMARY KEY (ISBN,PYEAR),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE CHECKS (
	ISBN	CHAR(13),
	EMP_ID	CHAR(9),
    WNAME VARCHAR(100),
    EX_QTY INT,
    IM_QTY INT,
	PRIMARY KEY (ISBN,EMP_ID,WNAME),
	FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (EMP_ID) REFERENCES EMPLOYEE(ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (WNAME) REFERENCES WAREHOUSE(WNAME) ON DELETE CASCADE ON UPDATE CASCADE
    
);

CREATE TABLE CUSTOMER (
	ID	CHAR(9),
	USERNAME	VARCHAR(20),
    PWD VARCHAR(20),
    PHONE CHAR(11),
    EMAIL VARCHAR(50),
    FNAME	VARCHAR(100) NOT NULL,
    LNAME	VARCHAR(100) NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE SHIPPING_METHOD(
    SID CHAR(9),
    FEE INT,
    PRIMARY KEY (SID)
);
CREATE TABLE ADDRESS_METHOD(
    SID CHAR(9),
    SHIPPING_ADDRESS VARCHAR(100),
    PRIMARY KEY (SID),
    FOREIGN KEY (SID) REFERENCES SHIPPING_METHOD(SID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE EMAIL_METHOD(
    SID CHAR(9),
    SHIPPING_EMAIL VARCHAR(50),
    PRIMARY KEY (SID),
    FOREIGN KEY (SID) REFERENCES SHIPPING_METHOD(SID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE BOOK_TRANSACTION (
	CID	CHAR(9),
    ISBN CHAR(13),
    PURCHASED_DATE datetime,
    TRANS_STATUS VARCHAR(50) CHECK (TRANS_STATUS IN ('WAITING','EXPORT','ERROR','SUCCESS')), /*special */
    FEEDBACK VARCHAR(100),
    TOTAL BIGINT,
    RESPONSE_DATE datetime,
    SHIPPING_ID CHAR(9),
    primary key (PURCHASED_DATE,CID,ISBN),
    FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (CID) REFERENCES CUSTOMER(ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (SHIPPING_ID) REFERENCES SHIPPING_METHOD(SID) ON DELETE CASCADE ON UPDATE CASCADE,
    CONSTRAINT CHK_RESPONSE CHECK (RESPONSE_DATE >= PURCHASED_DATE)
    
);

CREATE TABLE PAYMENT (
	ID	CHAR(9),
    PURCHASED_DATE datetime NOT NULL,
    PAYMENT_STATUS VARCHAR(50) CHECK (PAYMENT_STATUS IN ('PAID','UNPAID')), /*special */
    CID char(9),
    primary key (ID),
    FOREIGN KEY (PURCHASED_DATE,CID) REFERENCES BOOK_TRANSACTION(PURCHASED_DATE,CID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE TRANSFER (
	ID	CHAR(9),
    BANKING_DETAIL VARCHAR(100),
    primary key (ID),
    FOREIGN KEY (ID) REFERENCES PAYMENT(ID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE CREDIT_CARD (
	CCODE	CHAR(16),
    EXPIRATION_DATE date,
    ONAME	VARCHAR(100),
    BNAME VARCHAR(100),
    BRANCH_NAME VARCHAR(100),
	CID CHAR(9) NOT NULL,
    primary key (CCODE),
    FOREIGN KEY (CID) REFERENCES CUSTOMER(ID) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE CREDIT_PAYMENT (
	ID	CHAR(9),
    CREDIT_CODE CHAR(16) NOT NULL,
    primary key (ID),
    FOREIGN KEY (ID) REFERENCES PAYMENT(ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (CREDIT_CODE) REFERENCES CREDIT_CARD(CCODE) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE BOOK_IN_TRANSACTION (
	CID	CHAR(9),
    PURCHASED_DATE datetime,
    ISBN	CHAR(13),
    QTY INT,
	TRANS_TYPE VARCHAR(50) CHECK (TRANS_TYPE IN ('BORROW','BUY')),
    primary key (PURCHASED_DATE,CID,ISBN),
    FOREIGN KEY (CID) REFERENCES CUSTOMER(ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (PURCHASED_DATE) REFERENCES BOOK_TRANSACTION(PURCHASED_DATE) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE BUYS_BORROWS(
	CID	CHAR(9),
    ISBN	CHAR(13),
    QTY INT,
    BTIME datetime,
    primary key (CID,ISBN),
    FOREIGN KEY (CID) REFERENCES CUSTOMER(ID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (ISBN) REFERENCES BOOK(ISBN) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE COD(
  ID CHAR(9),
  DELIVERY_COMPANY VARCHAR(100),
  primary key (ID),
  FOREIGN KEY (ID) REFERENCES PAYMENT(ID) ON DELETE CASCADE ON UPDATE CASCADE
);