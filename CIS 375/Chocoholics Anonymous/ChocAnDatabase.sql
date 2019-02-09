use chocoholicsanonymous
go
CREATE TABLE [Member] (
    [MemberNumber] NUMERIC(9,0)  NOT NULL ,
    [Name] VARCHAR(25)  NOT NULL ,
    [Street] VARCHAR(25)  NOT NULL ,
    [City] VARCHAR(14)  NOT NULL ,
    [State] CHAR(2)  NOT NULL ,
    [ZipCode] NUMERIC(5)  NOT NULL ,
    [Email] VARCHAR(50)  NOT NULL ,
    [Status] NUMERIC(1,0)  NOT NULL , -- what data type should this be?
    CONSTRAINT [PK_Member]
        PRIMARY KEY CLUSTERED ([MemberNumber] ASC)
)

CREATE TABLE [Provider] (
    [ProviderNumber] NUMERIC(9, 0)  NOT NULL ,
    [Name] VARCHAR(25)  NOT NULL ,
    [Street] VARCHAR(25)  NOT NULL ,
    [City] VARCHAR(14)  NOT NULL ,
    [State] CHAR(2)  NOT NULL ,
    [ZipCode] NUMERIC(9, 0)  NOT NULL ,
    [Email] VARCHAR(50)  NOT NULL ,
    CONSTRAINT [PK_Provider]
        PRIMARY KEY CLUSTERED ([ProviderNumber] ASC)
)

CREATE TABLE [Service] (
    [ServiceCode] NUMERIC(6, 0)  NOT NULL ,
    [Name] VARCHAR(20)  NOT NULL ,
    [Fee] DECIMAL(5,2)  NOT NULL ,
    CONSTRAINT [PK_Service] 
        PRIMARY KEY CLUSTERED ([ServiceCode] ASC)
)

CREATE TABLE [ProvidedService] (
    [MemberNumber] NUMERIC(9,0)  NOT NULL ,
    [ProviderNumber] NUMERIC(9,0)  NOT NULL ,
    [ServiceCode] NUMERIC(6,0)  NOT NULL ,
    [DateProvided] DATE  NOT NULL ,
    [DateReceived] TIMESTAMP  NOT NULL ,
    [Comment] VARCHAR(100),
    CONSTRAINT [FK_ProvidedService_MemberNumber]
        FOREIGN KEY([MemberNumber]) REFERENCES [Member] ([MemberNumber]),
    CONSTRAINT [FK_ProvidedService_ProviderNumber]
        FOREIGN KEY([ProviderNumber]) REFERENCES [Provider] ([ProviderNumber]),
    CONSTRAINT [FK_ProvidedService_ServiceCode]
        FOREIGN KEY([ServiceCode]) REFERENCES [Service] ([ServiceCode])
)

CREATE TABLE [Transaction] (
    [TransactionNumber] NUMERIC(9, 0)  NOT NULL ,
    [MemberNumber] NUMERIC(9, 0)  NOT NULL ,
    [Amount] DECIMAL(5,2)  NOT NULL ,
    [Date] TIMESTAMP  NOT NULL ,
    CONSTRAINT [PK_Transaction] 
        PRIMARY KEY CLUSTERED ([TransactionNumber] ASC),
    CONSTRAINT [FK_Transaction_MemberNumber]
        FOREIGN KEY([MemberNumber]) REFERENCES [Member] ([MemberNumber]) 
)

CREATE TABLE [Employee] (
    [EmployeeNumber] NUMERIC(9, 0)  NOT NULL ,
    [Name] VARCHAR(25)  NOT NULL ,
    [PhoneNumber] NUMERIC(10, 0)  NOT NULL ,
    [Street] VARCHAR(25)  NOT NULL ,
    [City] VARCHAR(14)  NOT NULL ,
    [State] CHAR(2)  NOT NULL ,
    [ZipCode] NUMERIC(5, 0)  NOT NULL ,
    [Email] VARCHAR(50)  NOT NULL ,
    CONSTRAINT [PK_Employee]
        PRIMARY KEY CLUSTERED ([EmployeeNumber] ASC)
)
