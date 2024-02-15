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

<%	 try{
 		Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
PreparedStatement pst=con.prepareStatement("insert into ques values(?,?,?,?,?,?,?,?,?,?)");

pst.setInt(1,Integer.parseInt(request.getParameter("qno")));
pst.setString(2,request.getParameter("que"));
pst.setString(3,request.getParameter("ans"));
pst.setString(4,request.getParameter("opt1"));
pst.setString(5,request.getParameter("opt2"));
pst.setString(6,request.getParameter("opt3"));
pst.setString(7,request.getParameter("opt4"));
pst.setString(8,request.getParameter("exp"));
pst.setString(9,request.getParameter("sub"));
pst.setInt(10,Integer.parseInt(request.getParameter("mark")));

    int t=pst.executeUpdate();
    if(t>0)
     out.println("<h3 align=center> Question Inserted Successfully <br> <a href=InsertQs.jsp>Goto Insert Question</a>");
             con.close();
    }
            catch(Exception e){
                out.println(e);
            }

	
%>
	