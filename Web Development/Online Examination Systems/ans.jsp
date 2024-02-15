<%@ include file="connect.jsp" %>
<%! String str; int i = 0, mark = 0; %>

<%
	PreparedStatement pst = con.prepareStatement("select * from qs where type = ? order by qno");
	pst.setString(1,"os");
	ResultSet rs = pst.executeQuery();
	
	i = 0;
	mark = 0;
	str = "str";
	while(rs.next()){
		str = str+i;
		
		if( rs.getString(3).equals(request.getParameter(str)) ){
			mark = mark+rs.getInt(6);
		}
		i++;
	}
	out.println("<center> <h2>Your Marks Will be  = "+mark);
	
	con.close();
%>