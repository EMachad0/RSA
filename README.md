# RSA
C++ RSA Generator and Breaker

## Prerequisites:
* g++
* GNU gmp library
* boost library

### To Compile:
```console
$ make
```

### To run:
```console
$ ./rsa
```

### Console Arguments:
```console
./rsa file                      # encript and decript file 
./rsa file -t                   # show elapsed time
./rsa file -t -d                # show the public keys
./rsa file -t -d -b             # break the public key
./rsa file -t -d -b --sz v      # set the public key bit size to v
```

### Break Speed
![Time](https://i.imgur.com/0oqPxJ0.png)

### Break Speed
![Time](https://i.imgur.com/0oqPxJ0.png)
