<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <!-- <title>Page Title</title> -->
    <link rel="stylesheet" type="text/css" href="../main.css" />
</head>
<body>
    <main>
	  	<h3>Results</h3>
			<table>
				<tr>
					<th>Name</th>
					<th>Email Address</th>
					<th>City</th>
					<th></th>
				</tr>
				<?php foreach ($customerList as $customer): ?>
				<tr>
					<td><?php echo $customer['firstName'] . " " . $customer['lastName']; ?></td>
					<td><?php echo $customer['email']; ?></td>
					<td><?php echo $customer['city']; ?></td>
					<td>
						<form action="customer_view_update.php" method="post">
							<input type="hidden" name="customerID" value="<?php echo $customer['customerID'] ?>">
							<input type="submit" value="Select">
						</form>
					</td>
				</tr>
			    <?php endforeach; ?>
		</table>
    </main>
</body>
</html>