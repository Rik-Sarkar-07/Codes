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


<form action=SubmitAns.jsp method=post>
<table align=center>
	<% int j = 0; while(rs.next()){ ans1 = "ans"+j;   %>
     <tr>
          <td> <h3> Question <%=rs.getInt(1)%> <h3> </td>
          <td> <h3> <%=rs.getString(2)%> [<%=rs.getInt(10)%> Marks] <h3> </td>
     </tr>
    <tr>
         <td> Option 1 </td>
         <td> <%=rs.getString(4)%> </td>
    </tr>
    <tr>
	<td>Option 2</td>
        <td><%=rs.getString(5)%></td>
    </tr>
   <tr>
	<td> Option 3</td>
        <td><%=  rs.getString(6)%></td>
    </tr>
    <tr>
	<td> Option 4</td>
        <td><%=  rs.getString(7)%></td>
    </tr>
   <tr>
         <td>Write Your Answer </td>
        <td><input type=text name= <%=ans1%> ></td>
    </tr>
	<% j = j+1; }  
     con.close();
            }
            catch(Exception e){
                out.println(e);
            }
    %>
    <tr>
      <td colspan=2 align=center><input type=submit value = Submit></td>
     </tr> 
</table></form>
  