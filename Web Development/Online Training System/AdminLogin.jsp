<html>
    <head> <title> DataBase </title> </head>
    <body> 
        <%@ page import="java.sql.*" %>
        <% 
            String str = request.getParameter("pass");
            try{
 		Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
            Statement stmt = con.createStatement();
            ResultSet rs1 = stmt.executeQuery("select * from admin");
             while (rs1.next())
                if(str.equals(rs1.getString(1)))
                    response.sendRedirect("AdminHome.html");
                else{
                    response.sendRedirect("Admin.html");    
		}
             con.close();
            }
            catch(Exception e){
                out.println(e);
            }
        %>

    </body>
</html>