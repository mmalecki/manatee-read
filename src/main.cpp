#include <stdlib.h>
#include <ImageMagick-6/Magick++.h>
#include <BarcodeScanner.h>

#include <iostream>

using namespace std;
using namespace Magick;

int main(int argc,char **argv) {
  InitializeMagick(*argv);

  Image image(argv[1]);
  unsigned int width = image.columns();
  unsigned int height = image.rows();

  Blob raw;
  image.modifyImage();
  image.write(&raw, "GRAY", 8);
  const void *data = raw.data();

  cout << "Read image: " << height << " x " << width << " (" << raw.length() << ")" << endl;

  MWB_setActiveCodes(MWB_CODE_MASK_PDF);
  MWB_setDirection(MWB_SCANDIRECTION_HORIZONTAL | MWB_SCANDIRECTION_VERTICAL);
  MWB_setLevel(5);

  uint8_t* decoded;
  int i = MWB_scanGrayscaleImage((uint8_t*) data, width, height, &decoded);
  cout << "Manatee returned " << i << endl;
  cout << (char*) decoded;
  return 0;
}
