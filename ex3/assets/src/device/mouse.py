import struct 
f = open( "/dev/input/mice", "rb" ); 

# Open the file in the read-binary mode
while True:
  # Reads the 24 bytes 
  data = f.read(3)
  # Unpack the bytes to integers
  print(struct.unpack('bbb',data))  
