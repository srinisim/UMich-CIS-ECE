<?php include '../view/header.php'; ?>
<?php if(isset($_POST['emailSearched'])): ?>
	<?php 
		try {
			require __DIR__ . "/../model/database.php";
			require __DIR__ . "/../model/incidents_db.php";

			$email = filter_input(INPUT_POST, 'emailSearched');
			$customer = get_customer_name_by_email($email);
			$products = get_all_productCodes();

			session_start();
			$_SESSION['customerID'] = $customer['customerID'];
		}
		catch (Exception $e) {
			echo 'Caught exception: ',  $e->getMessage(), "\n";
		}
	?>
<?php endif ?>

<!DOCTYPE <!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<!-- <title>Page Title</title> -->
		<link rel="stylesheet" type="text/css" media="screen" href="../main.css" />
	</head>
	<body>
		<main>
			<div id=aligned>
				<label for="customerName">Customer: </label>
				<p name="customerName"><?php echo $customer['firstName'] . " " . $customer['lastName'];?></p>
			</div><br>
			<form action="incident_successful.php" method="post">
				<div id=aligned>
					<label for="selectedProduct">Product: </label>
					<select name="selectedProduct">
						<?php foreach ($products as $product): ?>
							<option value="<?php echo $product['name'] ?>"><?php echo $product['name'] ?></option>
						<?php endforeach; ?>
					</select>
				</div>
				<div id=aligned>
					<label for="title">Title: </label>
					<input name="title" type="text">
				</div><br>
				<div id=aligned>
					<label for="description">Description: </label>
					<textarea name="description" rows="5" cols="50"></textarea>
				</div><br>

				<input type="submit" name="incident" value="Update Customer">
			</form>
		</main>
	</body>
</html>
<?php

?>
<?php include '../view/footer.php'; ?>