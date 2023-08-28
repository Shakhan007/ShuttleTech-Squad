<!DOCTYPE html>
<html>
<head>
    <title>Shuttle Dashboard</title>
        <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f5f5f5;
        }
        h1 {
            text-align: center;
            padding: 20px;
            background-color: #333;
            color: white;
        }
        h2 {
            font-size: 20px;
            margin-top: 30px;
        }
        ul {
            list-style: none;
            padding-left: 0;
        }
        li {
            margin-bottom: 10px;
            padding: 10px;
            background-color: #fff;
            border: 1px solid #ddd;
            border-radius: 5px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        button {
            padding: 5px 10px;
            background-color: #333;
            color: white;
            border: none;
            border-radius: 3px;
            cursor: pointer;
        }
        a {
            display: block;
            margin-top: 20px;
            text-align: center;
            color: #333;
        }
        a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <h1>Shuttle Dashboard</h1>
    <h2>Available Seats:</h2>
    <ul id="available-seats">
        <?php
        // Connect to the database
        $conn = new mysqli("localhost", "root", "", "shuttle_booking");
        
        // Fetch and display available seats
        $query = "SELECT * FROM seats WHERE is_booked = 0";
        $result = $conn->query($query);
        while ($row = $result->fetch_assoc()) {
            $buttonText = $row['is_booked'] == 0 ? 'Book' : 'Booked';
            echo "<li>{$row['seat_number']} <button onclick='bookSeat(\"{$row['seat_number']}\")'>$buttonText</button></li>";
        }
        
        // Close the database connection
        $conn->close();
        ?>
    </ul>
    <a href="index.html">Go to Homepage</a>
    <script>
        function bookSeat(seatNumber) {
            if (confirm("Do you want to book seat " + seatNumber + "?")) {
                var xhr = new XMLHttpRequest();
                xhr.open("POST", "book_seat.php", true);
                xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
                xhr.onreadystatechange = function() {
                    if (xhr.readyState === 4 && xhr.status === 200) {
                        var button = document.querySelector("[onclick='bookSeat(\"" + seatNumber + "\")']");
                        if (button) {
                            button.textContent = "Booked";
                            button.setAttribute("disabled", "true");
                        }
                    }
                };
                xhr.send("seat_number=" + seatNumber);
            }
        }
    </script>
</body>
</html>
