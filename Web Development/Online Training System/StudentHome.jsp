<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home Page</title>
</head>
<body>
 <style>
      body {
        background-image: url("p7.jpg");
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: cover;
      }
    </style>
   <center>
        	<h1> Welcome <%=(String)session.getAttribute("name")%></h1>
    	 </center>
    	  <center>
     		 <h2> <a href="Admin.html">Instructor</a> || <a href="Home.html">Home</a> </h2>
		 <h1> <b> Your Subjects </h1>
     <h3> <a href="Example.jsp">C Programming</a> </h3>
		<h3> <a href="Student.jsp">C++ Programming</a> </h3>
		<h3> <a href="OS.html">Opearting System</a> </h3>
          </center>  
</body>
</html>