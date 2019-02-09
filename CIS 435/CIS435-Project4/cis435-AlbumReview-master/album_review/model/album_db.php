<?php 
    function insert_album($title, $artist, $albumCover, $releaseDate) {
        require 'database.php';
        global $db;

        $query = 'INSERT 
        INTO 
            albums (title, artist, albumCover, rating, releaseDate) 
        VALUES (:title, :artist, :albumCover, NULL, releaseDate)';

        $statement = $db->prepare($query);
        $statement->bindValue(':title', $title);
        $statement->bindValue(':artist', $artist);
        $statement->bindValue(':albumCover', $albumCover);
        // $statement->bindValue(':rating', NULL);
        $statement->bindValue(':releaseDate', $releaseDate);
        $statement->execute();
        $statement->closeCursor();
    }

    function update_album_rating($albumID, $rating) {
        require 'database.php';
        global $db;

        $query = 'UPDATE 
        INTO 
            albums (rating) 
        VALUES (:rating)
        WHERE albumID = :albumID';

        $statement = $db->prepare($query);
        $statement->bindValue(':rating', $rating);
        $statement->execute();
        $statement->closeCursor();
    }

    function select_all_albums() {
        require 'database.php';
        global $db;

        $query = 'SELECT
            *
        FROM
            albums
        ORDER BY
            rating
        DESC';

        $statement = $db->prepare($query);
        $statement->execute();
        $albums = $statement->fetchAll();
        $statement->closeCursor();

        return $albums;    
    }
?>