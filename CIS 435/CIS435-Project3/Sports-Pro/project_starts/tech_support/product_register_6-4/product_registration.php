<?php include '../view/header.php'; ?>
<?php if(isset($_POST['loginEmail'])): ?>
			<?php 
				try {
					require __DIR__ . "/../model/database.php";
					require __DIR__ . "/../model/registrations_db.php";
								
					$email = $_POST['loginEmail'];
					$customer = get_customer_by_email($email);
					$products = get_all_productCodes();
					$currentDate = date('Y-m-d');

					session_start();
					$_SESSION['customerID'] = $customer['customerID'];
				}
				catch (Exception $e) {
					echo 'Caught exception: ',  $e->getMessage(), "\n";
				}
			?>
<?php endif; ?>
<!DOCTYPE <!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<!-- <title>Page Title</title> -->
	<link rel="stylesheet" type="text/css" media="screen" href="../main.css" />

</head>
<body>
	<main>
		<h3>Register Product</h3>
		<div id="aligned">
			<label for="customer">Customer: </label>
			<p name="customer"><?php echo $customer['firstName'] . " " . $customer['lastName'];?></p>
		</div>

		<form action="product_successful.php" method="post">
			<div id="aligned">
				<label for="selectedProduct">Product: </label>
				<select name="selectedProduct">
					<?php foreach ($products as $product): ?>
						<option value="<?php echo $product['name'] ?>"><?php echo $product['name'] ?></option>
					<?php endforeach; ?>
				</select>
			</div>
			<div id="aligned">
				<label for="register"></label>
				<input name="register" type="submit" value="Register Product"><br>
			</div>
		</form>
	</main>
</body>
</html>
<?php include '../view/footer.php'; ?>