#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  bool results = false;
  std::ofstream image;
  image.open (filename);
  image << ("P3\n%d %d\n255\n", width, height);
  for (int i = 0; i < data.size(); i++)
  {
  	image << ("%d ", data[i]);
    if ((i + 1) % width == 0)
    {
		if (i == data.size() - 1)
		{
			results = true;
			break;
		}
		image << "\n";
	}
  }
  
  image.close ();
  
  return results;
  ////////////////////////////////////////////////////////////////////////////
}
