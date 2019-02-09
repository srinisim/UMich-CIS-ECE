<?php
    function select_players() {
        require 'database.php';
        global $db;
        
        $query = 'SELECT
            *
        FROM
            players
        ORDER BY
            wins DESC, losses ASC';

        $statement = $db->prepare($query);
        $statement->execute();
        $players = $statement->fetchAll();
        $statement->closeCursor();
     
        return $players;
    }

    function insert_player($firstName, $lastName) {
        require 'database.php';
        global $db;
        
        $query = 'INSERT
        INTO
            players (firstName, lastName, wins, loses)
        VALUES (:firstName, :lastName, 0, 0)';
        $statement = $db->prepare($query);
        $statement->bindValue(':firstName', $firstName);
        $statement->bindValue(':lastName', $lastName); 
        $statement->execute();
        $statement->closeCursor();       
    }

    function update_player_wins($playerID) {
        require 'database.php';
        global $db;

        $query = 'UPDATE
        players
        SET
        wins = wins + 1
        WHERE playerID = :playerID';

        $statement = $db->prepare($query);
        $statement->bindValue(':playerID', $playerID);
        $statement->execute();
        $statement->closeCursor();
    }

    function update_player_loses($playerID) {
        require 'database.php';
        global $db;

        $query = 'UPDATE
        players
        SET
        losses = losses - 1
        WHERE playerID = :playerID';

        $statement = $db->prepare($query);
        $statement->bindValue(':playerID', $playerID);
        $statement->execute();
        $statement->closeCursor();
    }
?>