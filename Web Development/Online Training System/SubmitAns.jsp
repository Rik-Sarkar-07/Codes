        <%@ page import="java.sql.*" %>
        <% 
		int qno;
		  String qs;
		  int marks;
		  String opt1;  String opt2;  String opt3;  String opt4;
		  String ans;
		  String exp;
		  String temp;
		  int i = 0;
		  int j = 0;
		  int tmarks = 0;
		  int m = 0;
		   out.println("<h1 align=center> Your Result !!   </h1>");
           out.println("<h2 align=center> <marquee> Answer With Explaination !!  </marquee> </h2>");
            try{
 		Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","SUDIPTA","80019");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from ques order by qno");
		i = 0;
		while(rs.next()){
			String ans1 = "ans"+i;
			i = i+1;
			String str = request.getParameter(ans1);
			
			qno =  rs.getInt(1);
			qs = rs.getString(2);	ans = rs.getString(3);  opt1 = rs.getString(4);   opt2 = rs.getString(5);  opt3 = rs.getString(6);  opt4 = rs.getString(7);   
			exp = rs.getString(8); marks = rs.getInt(10);

			tmarks = tmarks + marks;

			if(ans.equals(str)){
				out.println("<h4> Qs."+qno+" Correct Answer !! [+2 Marks] </h4>"+"[Your Ans = "+ans+"]<br> Explaination :-  "+ exp+"<br><br>");				
				m = m + marks;
			}
			else{
				out.println("<h4> Qs."+qno+" Incorrect Answer !! </h4>"+"[Your Ans = "+ans+"]<br> Explaination :-  "+ exp+"<br><br>");
			}
		}
		out.println("<h2 align=center > Your Progress = "+m+" [out of "+tmarks+"]</h>");
		out.println("<br><br><h3 align=center><a align=center href=StudentHome.jsp>Goto Student Home</a></h3>");	
             con.close();
            }
            catch(Exception e){
                out.println(e);
            }
        %>
