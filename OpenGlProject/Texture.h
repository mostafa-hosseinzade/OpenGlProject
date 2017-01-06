//-------------------------Texture Functions---------------------------------------------------
// Struct of bitmap file.
struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};

// Routine to read a bitmap file.
// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
  
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
 
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4); 
   
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->sizeX, 4);
   infile.read( (char *) &bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = bmp->sizeX * bmp->sizeY * 24;
   bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   { 
      temp = bmp->data[i];
	  bmp->data[i] = bmp->data[i+2];
	  bmp->data[i+2] = temp;
   }

   return bmp;
}


// Load external textures.
void loadExternalTextures(int ids ,string c)			
{
    
   // Local storage for bmp image data.
   BitMapFile *image[1];
   
   // Load the texture.
   image[0] = getBMPData("Textures/"+c); 
   
   
   // Activate texture index texture[0]. 
   //             // mitavand 1D va 3D ham bashad      texture feAly
   glBindTexture(GL_TEXTURE_2D                     ,   texture[ids]); 
   
   

   
   // Set texture parameters for wrapping.
   //parameter hay texture   _S ANd _T AbAd shekl
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // Set texture parameters for filtering.
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   // Specify an image as the texture to be bound with the currently active texture index.
    // dastor asli gozashtan akse 2D 
               // noe 2d or 3d   level    noe dadehay tasvir    mokhtasat sizeX  mokhtasat y
   glTexImage2D(GL_TEXTURE_2D,   0,      GL_RGB,          image[0]->sizeX, image[0]->sizeY,
            // hashie border
                0, 
	            //khod shekl     //byte ha mosbat     // dadehay aks
               GL_RGB, GL_UNSIGNED_BYTE,           image[0]->data);
}

void setupTextur(){
   // Create texture index array.
   //             teadad     //motagheyer texture
   glGenTextures(5,        texture); 

   // Load external texture and generate and load procedural texture.
   loadExternalTextures(0,"floor.bmp");
   loadExternalTextures(1,"pos_y.bmp");
   loadExternalTextures(2,"brick.bmp");
   loadExternalTextures(3,"images.bmp");
   loadExternalTextures(4,"crosshair.bmp");

   // Turn on OpenGL texturing.
   // faAl sazi texture 2D 
   glEnable(GL_TEXTURE_2D);

   // Specify how texture values combine with current surface color values.
   //parameter hay mohiti        set kardan  dadeha        jaygozin
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE     , GL_REPLACE); 

}