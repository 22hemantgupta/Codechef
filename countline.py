'''file = open("sam.txt","r") 
Counter = 0
  
# Reading from file 
Content = file.read() 
CoList = Content.split("\n") 
  
for i in CoList: 
    if i: 
        Counter += 1
          
print("This is the number of lines in the file") 
print(Counter)'''
def file_lengthy(fname):
        with open(fname) as f:
                for i, l in enumerate(f):
                        pass
        return i + 1
print("Number of lines in the file: ",file_lengthy("LabAssignment1.pdf"))
