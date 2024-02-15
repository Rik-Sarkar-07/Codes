<%@ include file="connect.jsp" %>
<%! String str; int i = 0; %>
<%
	PreparedStatement pst = con.prepareStatement("Select * from qs where type = ? order by qno");
	pst.setString(1,"os");
	
	ResultSet rs = pst.executeQuery();
	
%>	
	<center>
	<h1> Welcome <%=(String)session.getAttribute("name")%> </h1> <br>
	<h2>Operating Systems </h2>
	<form action=ans.jsp method=post>
	<%
	i = 0;
	str = "str";
	while(rs.next()){
		str = str+i;
		
		
		out.println("QNo "+rs.getString(1)+". "+rs.getString(2)+"[Marks = "+rs.getInt(6)+"]"+"<br><br>");
		%> 
		Write down Your Answer = <input type=text name=<%=str%>> <br><br><br>
		<%
		i++;
	}
	%>
	<h3><input type=submit value="Submit Your Answer">
	</form>
	<%
	con.close();
	%>