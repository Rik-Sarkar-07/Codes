<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
      <%@ page import="java.sql.*" %>
    <style>
      body {
        background-image: url("p9.jpg");
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: cover;
      }
    </style>
	<%!
		  int i = 0;
		  
		  String ans1;
	%>
        <% 
            try{
 		Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from ques order by qno");
            
        %>

<body>
    <form action=SubmitAns.jsp method=post>
   <% int j = 0; while(rs.next()){ ans1 = "ans"+j;   %>
        <ul class="quiz">
            <li>
                <h4>Question <%=rs.getInt(1)%></h4>
                <h4> <%=rs.getString(2)%> [<%=rs.getInt(10)%> Marks] <h4>
                <ul class="choices">
                    <li>
                        <label> 
                            A
                            <input type="radio" name= <%=ans1%> value= <%=rs.getString(4)%> /> 
                             <%=rs.getString(4)%>
                        </label
                        >
                    </li>
                     <li>
                        <label> 
                        B
                            <input type="radio" name= <%=ans1%> value= "<%=rs.getString(5)%>" /> 
                            <%=rs.getString(5)%>
                        </label
                        >
                    </li>
                     <li>
                        <label> 
                        C
                            <input type="radio" name= <%=ans1%> value= "<%=rs.getString(6)%>" /> 
                            <%=rs.getString(6)%>
                        </label
                        >
                    </li>
                     <li>
                        <label> 
                        D
                            <input type="radio" name= <%=ans1%> value= <%=rs.getString(7)%> /> 
                            <%=rs.getString(7)%>
                        </label
                        >
                    </li>
                </ul>
            </li>
            
        </ul>

    <% j = j+1; }  
     con.close();
            }
            catch(Exception e){
                out.println(e);
            }
    %>
 <h1 align=center>  <input type="submit" value="Submit" > </h1>

    </form>
   
</body>
</html>