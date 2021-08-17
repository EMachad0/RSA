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
$ ./rsa file                      # encript and decript file 
$ ./rsa file -t                   # show elapsed time
$ ./rsa file -d                   # show the public keys
$ ./rsa file -d -b                # break the public key
$ ./rsa file --sz v               # set the public key bit size to v
```

### Encription Speed
![Time](/plotting/time_test.png)

### Break Speed
![Time](/plotting/time_break.png)
