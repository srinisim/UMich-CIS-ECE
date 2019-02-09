<?php 
    function insertGame($minutesPlayed, $winnerID, $loserID) {
        require 'database.php';
        global $db;
        
        $query =
        'INSERT
        INTO
            games (minutesPlayed, winnerID, loserID)
        VALUES (:minutesPlayed, :winnerID, :loserID)';

        $statement = $db->prepare($query);
        $statement->bindValue(':gameID', $gameID);
        $statement->bindValue(':minutesPlayed', $minutesPlayed);
        $statement->bindValue(':winnerID', $winnerID);
        $statement->bindValue(':loserID', $loserID); 
        $statement->execute();
        $statement->closeCursor();    
    }
?>