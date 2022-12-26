xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 33;
 1.37906;-5.31944;-3.43432;,
 -1.20381;-1.75887;-3.43432;,
 15.29015;-2.89636;-3.43432;,
 12.29469;-5.31946;-3.43432;,
 -1.20381;1.80174;-3.43432;,
 15.29015;2.83398;-3.43432;,
 1.37906;5.36236;-3.43432;,
 12.29469;5.36228;-3.43432;,
 1.37906;5.36236;-3.43432;,
 1.37906;5.36236;3.44618;,
 12.29469;5.36228;3.44618;,
 12.29469;5.36228;-3.43432;,
 1.37906;5.36236;3.44618;,
 -1.20381;1.80174;3.44618;,
 15.29015;2.83398;3.44618;,
 12.29469;5.36228;3.44618;,
 -1.20381;-1.75887;3.44618;,
 15.29015;-2.89636;3.44618;,
 1.37906;-5.31944;3.44618;,
 12.29469;-5.31946;3.44618;,
 1.37906;-5.31944;3.44618;,
 1.37906;-5.31944;-3.43432;,
 12.29469;-5.31946;-3.43432;,
 12.29469;-5.31946;3.44618;,
 -1.20381;-1.75887;3.44618;,
 -1.20381;-1.75887;-3.43432;,
 -1.20381;1.80174;3.44618;,
 -1.20381;1.80174;-3.43432;,
 -1.20381;-1.75887;-3.43432;,
 15.29015;-2.89636;-3.43432;,
 15.29015;-2.89636;3.44618;,
 15.29015;2.83398;-3.43432;,
 15.29015;2.83398;3.44618;;
 
 14;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;13,16,17,14;,
 4;16,18,19,17;,
 4;20,21,22,23;,
 4;20,24,25,21;,
 4;24,26,27,28;,
 4;26,9,8,27;,
 4;22,29,30,23;,
 4;29,31,32,30;,
 4;31,11,10,32;;
 
 MeshMaterialList {
  5;
  14;
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/cookie000.png";
   }
  }
  Material {
   0.501600;0.408000;0.119200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/cookie000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/cookie_icing000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/button_icing000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data/TEXTURE/ribbon_icing000.png";
   }
  }
 }
 MeshNormals {
  10;
  0.000000;0.000000;-1.000000;,
  -0.454321;0.890838;0.000000;,
  0.000000;-0.000000;1.000000;,
  0.343383;0.939195;0.000000;,
  -0.454322;-0.890838;0.000000;,
  0.333562;-0.942728;-0.000000;,
  -0.951171;-0.308664;0.000000;,
  -0.951172;0.308661;0.000000;,
  0.902474;-0.430745;-0.000000;,
  0.906918;0.421306;0.000000;;
  14;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,3,3;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;4,4,5,5;,
  4;4,6,6,4;,
  4;6,7,7,6;,
  4;7,1,1,7;,
  4;5,8,8,5;,
  4;8,9,9,8;,
  4;9,3,3,9;;
 }
 MeshTextureCoords {
  33;
  0.591170;2.824651;,
  0.420416;2.589261;,
  1.510839;2.664460;,
  1.312808;2.824653;,
  0.420416;2.353867;,
  1.510839;2.285625;,
  0.591170;2.118473;,
  1.312808;2.118478;,
  0.060772;1.125382;,
  0.439417;1.125382;,
  0.293495;1.125386;,
  0.206648;1.125386;,
  0.591170;2.118473;,
  0.420416;2.353867;,
  1.510839;2.285625;,
  1.312808;2.118478;,
  0.420416;2.589261;,
  1.510839;2.664460;,
  0.591170;2.824651;,
  1.312808;2.824653;,
  0.439417;1.659472;,
  0.060772;1.659472;,
  0.206648;1.659473;,
  0.293495;1.659473;,
  0.553486;1.481444;,
  -0.053658;1.481444;,
  0.553486;1.303413;,
  0.946342;1.303413;,
  0.946342;1.481444;,
  0.214836;1.538318;,
  0.285282;1.538318;,
  0.214836;1.251801;,
  0.285282;1.251801;;
 }
}
