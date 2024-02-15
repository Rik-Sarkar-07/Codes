<html>
    <head> <title> DataBase </title> </head>
    <body> 
        <%@ page import="java.sql.*" %>
        <%! String i; %>
        <% 
            String str = request.getParameter("uid");
	    String str1 = request.getParameter("pass");
        
        
            try{
 		   Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
             PreparedStatement stmt =con.prepareStatement("select * from student where pass = ? and id = ?");
            stmt.setString(1,str1);
            stmt.setString(2,str);
            ResultSet rs1 = stmt.executeQuery();
                if(rs1.next()){
                    session.setAttribute("name",rs1.getString(3));
                    response.sendRedirect("StudentHome.jsp");   
                }
              else  
  	 	        response.sendRedirect("User.html"); 
             con.close();
            }
            catch(Exception e){
                out.println(e);
            }
        %>
    </body>
</html>