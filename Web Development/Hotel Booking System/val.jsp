<%@ include file="connect.jsp" %>
<% 

	PreparedStatement pst = con.prepareStatement("select * from student where id = ? and pass = ?");
	
	String nm = request.getParameter("nm");
	String ps = request.getParameter("ps");
	pst.setString(1,nm);
	pst.setString(2,ps);
	ResultSet rs = pst.executeQuery();
	if(rs.next()){
		session.setAttribute("name",rs.getString(3));
		response.sendRedirect("hotel.html");
	}
	else{
	response.sendRedirect("login.html");
	}
	con.close();

%>

