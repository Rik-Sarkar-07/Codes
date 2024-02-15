<%@ include file="connect.jsp" %>
<%
PreparedStatement pst = con.prepareStatement("select * from hotel where name = ? or place = ?");
pst.setString(1,request.getParameter("nm"));
pst.setString(2,request.getParameter("nm"));

ResultSet rs = pst.executeQuery();
%>
<center>
	<table>
		<tr>
			<th> Hotel Name </th>
			<th> Place </th>
			<th> Price </th>
			<th> Booking Link </th>
		</tr>
<%
while(rs.next()){
	%>
	
		<tr>
			<td> <%= rs.getString(1) %> </td>
			<td> <%= rs.getString(2) %> </td>
			<td> <%= rs.getString(3) %> </td>
			<td> <a href="<%=rs.getString(4)%>" > Click Here </a> </td>
		</tr>
		
	<%
}
%>
</table>
<%
con.close();
	

%>