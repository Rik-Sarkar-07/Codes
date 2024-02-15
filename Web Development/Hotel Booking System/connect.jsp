  <%@ page import="java.sql.*" %>
  <%! Connection con = null; %>
  <% 
 		Class.forName("oracle.jdbc.OracleDriver");
        con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
   %>