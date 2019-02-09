<?php
    function insert_critics($firstName, $lastName, $email, $password) {
        require 'database.php';
        global $db;

        $query =
        'INSERT
        INTO
            critics (firstName, lastName, email, password)
        VALUES (:firstName, :lastName, :email, :password)';

        $statement = $db->prepare($query);
        $statement->bindValue(':firstName', $firstName);
        $statement->bindValue(':lastName', $lastName);
        $statement->bindValue(':email', $email);
        $statement->bindValue(':password', $password);
        $statement->execute();
        $statement->closeCursor();
    }

    function get_critics_by_lastName($lastName) {
      require 'database.php';
      global $db;

      $query = 'SELECT
      firstName,
      lastName,
      email,
      password,
      criticID
      FROM critics
      WHERE lastName = :lastName';

      $statement = $db->prepare($query);
      $statement->bindValue(':lastName', $lastName);
      $statement->execute();
      $critics = $statement->fetchAll();
      $statement->closeCursor();

      return $critics;
  }

  function get_critic_by_id($criticID) {
      require 'database.php';
      global $db;

      $query =
      'SELECT
          firstName,
          lastName,
          email,
          password
      FROM critics WHERE criticID = :criticID';
      $statement = $db->prepare($query);
      $statement->bindValue(':criticID', $criticID);
      $statement->execute();
      $criticInfo = $statement->fetch();
      $statement->closeCursor();

      return $criticInfo;
  }

  function update_critic_by_id($firstName, $lastName, $email, $password, $criticID) {
      require 'database.php';
      global $db;

      $query = 'UPDATE
      critics
      SET
      firstName = :firstName,
      lastName = :lastName,
      email = :email,
      password = :password
      WHERE criticID = :criticID';

      $statement = $db->prepare($query);
      $statement->bindValue(':firstName', $firstName);
      $statement->bindValue(':lastName', $lastName);
      $statement->bindValue(':email', $email);
      $statement->bindValue(':password', $password);
      $statement->bindValue(':criticID', $criticID);
      $statement->execute();
      $statement->closeCursor();
  }
?>
