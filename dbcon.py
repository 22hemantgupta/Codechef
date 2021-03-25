import pymysql
import pymysql.cursors
db = pymysql.connect("localhost", "root", "h3m@nt1234", "test")
cursor = db.cursor()
sql3 = "select * from Employee1 "
cursor.execute(sql3)
result = cursor.fetchall()
for row in result:

    print(row[1])
db.close()
# for fetching information in
# fetch all this method is use to fetch multiple values from database
