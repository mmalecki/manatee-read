# manatee-read
Example of using [Manatee](http://manateeworks.com/) library for reading barcodes from file.

Mostly WIP/POC, lacking every feature known to human, but exactly what I'd be happy to find before I started writing this.

## Setup
Drop `BarcodeScanner.h` and `libBarcodeScanner.a` into `deps/manatee`.

## Caveats

  * Can't scan images bigger than 3000 x 3000 (Manatee's limitation).
