-- Create the album_review database
DROP DATABASE IF EXISTS album_review;
CREATE DATABASE album_review;
USE album_review;

CREATE TABLE albums (
    albumID int NOT NULL AUTO_INCREMENT,
    title varchar(50) NOT NULL,
    artist varchar(50) NOT NULL,
    ablumCover varchar(100) NOT NULL,
    rating float(2, 1),
    releaseDate datetime NOT NULL,
    PRIMARY KEY (albumID)
);

INSERT INTO albums VALUES 
(1, 'Astroworld', 'Travis Scott', 'CIS-435-ALBUM-REVIEW/album-review/resources/astroworld.png', 9.5, '2018-08-03'),
(2, 'Scorpion', 'Drake', 'CIS-435-ALBUM-REVIEW/album-review/resources/scorpion.png', 8.6, '2018-06-29'),
(3, 'Mudboy', 'Sheck Wes', 'CIS-435-ALBUM-REVIEW/album-review/resources/mudboy.png', 7.3, '2018-10-05'),
(4, 'Goodbye & Good Ridance', 'Juice WRLD', 'CIS-435-ALBUM-REVIEW/album-review/resources/goodbye_&_good_ridance.png', 8.8, '2018-05-23'),
(5, 'Sweetener', 'Ariana Grande', 'CIS-435-ALBUM-REVIEW/album-review/resources/sweetener.png', 9.1, '2018-08-17'),
(6, 'Tranquility Base Hotel and Casino', 'Arctic Monkeys', 'CIS-435-ALBUM-REVIEW/album-review/resources/base_hotel_and_casino.png', 5.2, '2018-05-11'),
(7, 'Boarding House Reach', 'Jack White', 'CIS-435-ALBUM-REVIEW/album-review/resources/boarding_house_reach.png', 6.4, '2018-03-23'),
(8, 'Little Dark Age', 'MGMT', 'CIS-435-ALBUM-REVIEW/album-review/resources/little_dark_age.png', 2.9, '2018-08-03'),
(9, 'Hive Mind', 'The Internet', 'CIS-435-ALBUM-REVIEW/album-review/resources/hive_mind.png', 8.2, '2018-07-20'),
(10, 'Kids See Ghosts', 'Kid Cudi', 'CIS-435-ALBUM-REVIEW/album-review/resources/kids_see_ghosts.png', 8.4, '2018-06-08');

CREATE TABLE critics (
    criticID int NOT NULL AUTO_INCREMENT,
    firstName varchar(50) NOT NULL,
    lastName varchar(50) NOT NULL,
    email varchar(50) NOT NULL UNIQUE,
    password varchar(20) NOT NULL,
    PRIMARY KEY (criticID)
);

INSERT INTO critics VALUES 
(1, 'Omari', 'Chatman', 'ochatman@umich.edu', 'sesame'),
(2, 'Dujon', 'Brown-Deacon', 'dbrownde@umich.edu', 'sesame'),
(3, 'Srinivas', 'Simhan', 'simhan@umich.edu', 'sesame');

CREATE TABLE administrators (
  username    VARCHAR(40)    NOT NULL     UNIQUE,
  password    VARCHAR(40)    NOT NULL,
  PRIMARY KEY (username)
);

INSERT INTO administrators VALUES
('omari', 'sesame'),
('srinivas', 'sesame'),
('dujon', 'sesame');

-- Create a user named ar_user
GRANT SELECT, INSERT, UPDATE, DELETE
ON *
TO ar_user@localhost
IDENTIFIED BY 'pa55word';