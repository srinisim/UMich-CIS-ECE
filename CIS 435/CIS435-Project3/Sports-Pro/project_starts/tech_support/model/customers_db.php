<?php 
    function get_customers_by_lastName($lastName) {
        require 'database.php';
        global $db;

        $query = 'SELECT 
        firstName, 
        lastName, 
        email, 
        city, 
        customerID 
        FROM customers 
        WHERE lastName = :lastName';

        $statement = $db->prepare($query);
        $statement->bindValue(':lastName', $lastName);
        $statement->execute();
        $customers = $statement->fetchAll();
        $statement->closeCursor();

        return $customers;
    }

    function get_customer_by_id($customerID) {
        require 'database.php';
        global $db;

        $query = 
        'SELECT 
            firstName, 
            lastName, 
            address, 
            city, 
            state, 
            postalCode, 
            countryCode, 
            phone, 
            email, 
            password
        FROM customers WHERE customerID = :customerID';
        $statement = $db->prepare($query);
        $statement->bindValue(':customerID', $customerID);
        $statement->execute();
        $customerInfo = $statement->fetch();
        $statement->closeCursor();

        return $customerInfo;
    }

    function update_customer_by_id($firstName, $lastName, $address, $city, $state, $postalCode, $countryCode, $phone, $email, $password, $customerID) {
        require 'database.php';
        global $db;

        $query = 'UPDATE 
        customers 
        SET 
        firstName = :firstName, 
        lastName = :lastName, 
        address = :address, 
        city = :city, 
        state = :state, 
        postalCode = :postalCode, 
        countryCode = :countryCode, 
        phone = :phone, 
        email = :email, 
        password = :password 
        WHERE customerID = :customerID';

        $statement = $db->prepare($query);
        $statement->bindValue(':firstName', $firstName);
        $statement->bindValue(':lastName', $lastName);
        $statement->bindValue(':address', $address);
        $statement->bindValue(':city', $city);
        $statement->bindValue(':state', $state);
        $statement->bindValue(':postalCode', $postalCode);
        $statement->bindValue(':countryCode', $countryCode);
        $statement->bindValue(':phone', $phone);
        $statement->bindValue(':email', $email);
        $statement->bindValue(':password', $password);
        $statement->bindValue(':customerID', $customerID);
        $statement->execute();
        $statement->closeCursor();
    }
?>