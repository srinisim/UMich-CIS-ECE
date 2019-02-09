<?php include '../view/header.php'; ?>

<!DOCTYPE <!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<!-- <title>Page Title</title> -->
		<link rel="stylesheet" type="text/css" href="../main.css" />
	</head>
	<body>
		<main>
			<?php if (isset($_POST['customerID'])): ?>
				<?php
					try {
						require __DIR__ . "/../model/database.php";
						require __DIR__ . "/../model/customers_db.php";
	
						$customerID =  filter_input(INPUT_POST, 'customerID');

						session_start();
						$_SESSION["custo_ID"] = $customerID;

						$customer = get_customer_by_id($customerID);
					}
					catch (Exception $e) {
						echo 'Caught exception: ',  $e->getMessage(), "\n";
					}
				?>

				<form id="aligned" action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> method="post">
				<!-- <form id="aligned" action="customer_successful.php"> method="post"> -->
					<label for="firstNameUpdated">First Name: </label>
					<input type="text" name="firstNameUpdated" value="<?php echo $customer['firstName'] ?>"><br>

					<label for="lastNameUpdated">Last Name: </label>
					<input type="text" name="lastNameUpdated" value="<?php echo $customer['lastName'] ?>"><br>

					<label for="addressUpdated">Address: </label>
					<input type="text" name="addressUpdated" value="<?php echo $customer['address'] ?>"><br>

					<label for="cityUpdated">City: </label>
					<input type="text" name="cityUpdated" value="<?php echo $customer['city'] ?>"><br>

					<label for="stateUpdated">State: </label>
					<input type="text" name="stateUpdated" value="<?php echo $customer['state'] ?>"><br>

					<label for="postalCodeUpdated">Postal Code: </label>
					<input type="text" name="postalCodeUpdated" value="<?php echo $customer['postalCode'] ?>"><br>

					<label for="countryCodeUpdated">Country Code: </label>
					<input type="text" name="countryCodeUpdated" value="<?php echo $customer['countryCode'] ?>"><br>

					<label for="phoneUpdated">Phone: </label>
					<input type="text" name="phoneUpdated" value="<?php echo $customer['phone'] ?>"><br>

					<label for="emailUpdated">Email: </label>
					<input type="text" name="emailUpdated" value="<?php echo $customer['email'] ?>"><br>

					<label for="passwordUpdated">Password: </label>
					<input type="text" name="passwordUpdated" value="<?php echo $customer['password'] ?>"><br>

					<input type="submit" name= "update" value="Update Customer">
				</form>
			<?php endif; ?>

			<?php if(isset($_POST['update'])): ?>
				<?php
					try {
						require __DIR__ . "/../model/database.php";
						require __DIR__ . "/../model/customers_db.php";
	
						$firstname = filter_input(INPUT_POST, 'firstNameUpdated');
						$lastname = filter_input(INPUT_POST, 'lastNameUpdated');
						$address = filter_input(INPUT_POST, 'addressUpdated');
						$city = filter_input(INPUT_POST, 'cityUpdated');
						$state = filter_input(INPUT_POST, 'stateUpdated');
						$postalcode = filter_input(INPUT_POST, 'postalCodeUpdated');
						$countrycode = filter_input(INPUT_POST, 'countryCodeUpdated');
						$phone = filter_input(INPUT_POST, 'phoneUpdated');
						$email = filter_input(INPUT_POST, 'emailUpdated');
						$password = filter_input(INPUT_POST, 'passwordUpdated');

						session_start();
						$customerID = $_SESSION["custo_ID"];
	
						update_customer_by_id($firstname, $lastname, $address, $city, $state, $postalcode, $countrycode, $phone, $email, $password, $customerID);
	
						// echo "<p>Updated</p>";
						// echo "<p>$firstname</p>";
						// echo "<p>$lastname</p>";
						// echo "<p>$address</p>";
						// echo "<p>$city</p>";
						// echo "<p>$state</p>";
						// echo "<p>$postalcode</p>";
						// echo "<p>$countrycode</p>";
						// echo "<p>$phone</p>";
						// echo "<p>$email</p>";
						// echo "<p>$password</p>";
						// echo "<p>$customerID</p>";
					}
					catch (Exception $e) {
						echo 'Caught exception: ',  $e->getMessage(), "\n";
					}
				?>
			<?php endif; ?>

			<a href="index.php">Search Customers</a>
		</main>
	</body>
</html>

<?php include '../view/footer.php'; ?>