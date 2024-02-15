<%@include file="connect.jsp" %>
<%
	PreparedStatement pst = con.prepareStatement("insert into book1 values(?,?,?)");
	pst.setString(1,(String)session.getAttribute("name"));
	pst.setString(2,request.getParameter("nm"));
	pst.setString(3,request.getParameter("cn"));
	int t = pst.executeUpdate();
	if(t>0){
		out.println("<center> <h2> Hotel Booking Completed, Happy Holiday !! </h2> ");
	}
	con.close();
%>
