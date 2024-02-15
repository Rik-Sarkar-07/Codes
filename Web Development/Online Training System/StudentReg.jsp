 <%@ page import="java.sql.*" %>
 <% 
           
       try{
            Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
            PreparedStatement stmt =con.prepareStatement("insert into student values(?,?,?)");
	String u = request.getParameter("uid");
	String r = request.getParameter("pass");
	String n = request.getParameter("name1");
	
	 stmt.setString(1,request.getParameter("uid"));
  	stmt.setString(2,request.getParameter("pass"));
 	 stmt.setString(3,request.getParameter("name1"));
		
            int i = stmt.executeUpdate();
	    if(i>0){
		out.println("<h2 align=center> Your Registration Done! [Mr. "+n+"]</h2> <br> <h3 align=center> Goto Login Page <a href=User.html>Login</a> </h3>");
	    }
			
          con.close();
   }  
          catch(Exception e){
                out.println(e);
            }
%>