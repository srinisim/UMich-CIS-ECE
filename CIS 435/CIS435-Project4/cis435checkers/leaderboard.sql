-- Create the leaderboard database
DROP DATABASE IF EXISTS leaderboard;
CREATE DATABASE leaderboard;
USE leaderboard;

CREATE TABLE players (
    playerID int NOT NULL AUTO_INCREMENT,
    firstName varchar(50) NOT NULL,
    lastName varchar(50) NOT NULL,
    wins int NOT NULL,
    losses int NOT NULL,
    PRIMARY KEY (playerID)
);

INSERT INTO players VALUES
(3, 'Dujon', 'Brown', 2, 3),
(1, 'Omari', 'Chatman', 4, 2),
(2, 'Srinivas', 'Simhan', 1, 2);

CREATE TABLE games (
    gameID int NOT NULL AUTO_INCREMENT,
    minutesPlayed int NOT NULL,
    secondsPlayed int NOT NULL,
    winnerID int NOT NULL,
    loserID int NOT NULL,
    PRIMARY KEY (gameID)
);

INSERT INTO games VALUES 
(1, 12, 5, 1, 2),
(2, 21, 34, 2, 1),
(3, 17, 25, 3, 1),
(4, 32, 11, 2, 3),
(5, 50, 17, 2, 1),
(6, 5, 54, 2, 3),
(7, 44, 1, 3, 2);

CREATE TABLE administrators (
  username    VARCHAR(40)    NOT NULL     UNIQUE,
  password    VARCHAR(40)    NOT NULL,
  PRIMARY KEY (username)
);

INSERT INTO administrators VALUES
('omari', 'sesame'),
('srinivas', 'sesame'),
('dujon', 'sesame');


-- Create a user named ts_user
GRANT SELECT, INSERT, UPDATE, DELETE
ON *
TO cg_user@localhost
IDENTIFIED BY 'pa55word';