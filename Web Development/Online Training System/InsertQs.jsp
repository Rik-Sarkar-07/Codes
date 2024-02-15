 <%@ page import="java.sql.*" %>
	<%!
  		  int qno = 0;
		  String qs;
		  int marks = 0;
		  String opt1;  String opt2;  String opt3;  String opt4;
		  String ans;
		  String exp;
		  String temp;
	%>
        <% 
            try{
 		Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select max(qno) from ques");
		if(rs.next()){
			qno = rs.getInt(1);
		}
		qno = qno + 1;
             con.close();
            }
            catch(Exception e){
                out.println(e);
            }
        %>

<form action=BookInserted.jsp method=post>
 <style>
      body {
        background-image: url("p4.jpg");
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: cover;
      }
    </style>
<h1 align="center">Insert New Question</h1>
 <h2 align="center"><a href="Home.html">Home</a> || <a href="AdminHome.html">Instructor</a></h3>
<table align="center">
     <tr>    
         <td><b>Question No.</td>
         <td><input type=text name=qno value=<%=qno%> readonly>
          </td>
     </tr>
     <tr>
          <td><b> Enter Question </td>
          <td><input type=text name=que></td>
     </tr>
    <tr>
         <td><b> Option 1 </td>
         <td><input type=text name=opt1></td>
    </tr>
    <tr>
	<td><b>Option 2 </td>
        <td><input type=text name=opt2></td>
    </tr>
   <tr>
	<td> <b>Option 3 </td>
        <td><input type=text name=opt3></td>
    </tr>
   <tr>
         <td><b>Option 4 </td>
        <td><input type=text name=opt4></td>
    </tr>
   <tr>
         <td><b>Correct Answer </td>
        <td><input type=text name=ans></td>
    </tr>
    <tr>
         <td><b>Marks </td>
        <td><input type=text name=mark></td>
    </tr>
    <tr>
         <td><b>Explaination </td>
        <td><input type=text name=exp></td>
    </tr>
 	<tr>
         <td><b>Subject</td>
        <td><input type=text name=sub></td>
    </tr>
    <tr>
      <td colspan=2 align=center><input type=submit value=Insert></td>
     </tr>
</table></form>
  
