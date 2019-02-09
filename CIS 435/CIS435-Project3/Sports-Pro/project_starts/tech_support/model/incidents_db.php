<?php 
    function get_customer_name_by_email($email) {
        require 'database.php';
        global $db;

        $query = 
        'SELECT 
            firstName, 
            lastName,
            customerID
        FROM customers 
        WHERE email = :email';
        $statement = $db->prepare($query);
        $statement->bindValue(':email', $email);
        $statement->execute();
        $customer = $statement->fetch();
        $statement->closeCursor();

        return $customer;
    }

    function get_all_productCodes() {
        require 'database.php';
        global $db;

        $query = 
        'SELECT
            name,
            productCode
        FROM products';
        $statement = $db->prepare($query);
        $statement->execute();
        $productCodes = $statement->fetchAll();
        $statement->closeCursor();

        return $productCodes;
    }

    function insert_incidents($customerID, $productCode, $dateOpened, $title, $description) {
        require 'database.php';
        global $db;

        $query = 
        'INSERT 
        INTO 
            incidents (customerID, productCode, dateOpened, title, description) 
        VALUES (:customerID, :productCode, :dateOpened, :title, :description)';
        $statement = $db->prepare($query);
        $statement->bindValue(':customerID', $customerID);
        $statement->bindValue(':productCode', $productCode);
        $statement->bindValue(':dateOpened', $dateOpened);
        $statement->bindValue(':title', $title);
        $statement->bindValue(':description', $description);
        $statement->execute();
        $statement->closeCursor();
    }

    function get_productCodes_by_productName($productName) {
        require 'database.php';
        global $db;

        $query = 
        'SELECT
            productCode 
        FROM  
            products
        WHERE name = :productName';
        $statement = $db->prepare($query);
        $statement->bindValue(':productName', $productName);
        $statement->execute();
        $productCode = $statement->fetch();
        $statement->closeCursor();

        return $productCode;
    }
    
?>