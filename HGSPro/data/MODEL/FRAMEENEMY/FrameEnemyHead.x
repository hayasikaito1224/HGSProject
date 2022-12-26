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
 160;
 0.00000;30.71544;-31.80726;,
 0.00000;36.90507;-15.10578;,
 10.68140;36.90507;-10.68140;,
 22.49113;31.24336;-22.49113;,
 15.10578;36.90507;0.00000;,
 31.80726;32.67018;0.00000;,
 10.68140;36.90507;10.68140;,
 22.49113;31.24336;22.49113;,
 -0.00000;36.90507;15.10578;,
 -0.00000;30.71544;31.80726;,
 -10.68140;36.90507;10.68139;,
 -22.49114;31.24336;22.49113;,
 -15.10578;36.90507;-0.00000;,
 -31.80726;32.67018;-0.00000;,
 -10.68140;36.90507;-10.68139;,
 -22.49113;31.24336;-22.49113;,
 0.00000;36.90507;-15.10578;,
 0.00000;30.71544;-31.80726;,
 0.00000;63.89368;1.23031;,
 1.80051;63.89368;1.97610;,
 2.54631;63.89368;3.77661;,
 1.80051;63.89368;5.57713;,
 -0.00000;63.89368;6.32293;,
 -1.80051;63.89368;5.57713;,
 -2.54631;63.89368;3.77661;,
 -1.80051;63.89368;1.97610;,
 0.00000;63.89368;1.23031;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 -7.02292;71.53091;13.00782;,
 0.00000;40.86726;0.00000;,
 -6.67394;39.32170;-6.67394;,
 -9.43836;39.32170;0.00000;,
 0.00000;40.86726;0.00000;,
 0.00000;39.32170;-9.43836;,
 0.00000;40.86726;0.00000;,
 6.67394;39.32170;-6.67394;,
 0.00000;40.86726;0.00000;,
 9.43836;39.32170;0.00000;,
 0.00000;40.86726;0.00000;,
 6.67394;39.32170;6.67394;,
 0.00000;40.86726;0.00000;,
 0.00000;39.32170;9.43836;,
 0.00000;40.86726;0.00000;,
 -6.67394;39.32170;6.67394;,
 0.00000;40.86726;0.00000;,
 -9.43836;39.32170;0.00000;,
 -12.33182;34.92034;-12.33182;,
 -17.43985;34.92034;0.00000;,
 0.00000;34.92034;-17.43985;,
 12.33182;34.92034;-12.33182;,
 17.43985;34.92034;0.00000;,
 12.33182;34.92034;12.33182;,
 0.00000;34.92034;17.43985;,
 -12.33182;34.92034;12.33182;,
 -17.43985;34.92034;0.00000;,
 -16.11230;28.33327;-16.11230;,
 -22.78623;28.33327;0.00000;,
 0.00000;28.33327;-22.78623;,
 16.11230;28.33327;-16.11230;,
 22.78623;28.33327;0.00000;,
 16.11230;28.33327;16.11232;,
 0.00000;28.33327;22.78623;,
 -16.11230;28.33327;16.11232;,
 -22.78623;28.33327;0.00000;,
 -17.43985;20.56335;-17.43985;,
 -24.66363;20.56335;0.00000;,
 0.00000;20.56335;-24.66363;,
 17.43985;20.56335;-17.43985;,
 24.66363;20.56335;0.00000;,
 17.43985;20.56335;17.43985;,
 0.00000;20.56335;24.66363;,
 -17.43985;20.56335;17.43985;,
 -24.66363;20.56335;0.00000;,
 -16.11230;12.79330;-16.11230;,
 -22.78623;12.79330;0.00000;,
 0.00000;12.79330;-22.78623;,
 16.11230;12.79330;-16.11230;,
 22.78623;12.79330;0.00000;,
 16.11230;12.79330;16.11232;,
 0.00000;12.79330;22.78623;,
 -16.11230;12.79330;16.11232;,
 -22.78623;12.79330;0.00000;,
 -12.33182;6.20623;-12.33182;,
 -17.43985;6.20623;0.00000;,
 0.00000;6.20623;-17.43985;,
 12.33182;6.20623;-12.33182;,
 17.43985;6.20623;0.00000;,
 12.33182;6.20623;12.33182;,
 0.00000;6.20623;17.43985;,
 -12.33182;6.20623;12.33182;,
 -17.43985;6.20623;0.00000;,
 -6.67394;1.80490;-6.67394;,
 -9.43836;1.80490;0.00000;,
 0.00000;1.80490;-9.43836;,
 6.67394;1.80490;-6.67394;,
 9.43836;1.80490;0.00000;,
 6.67394;1.80490;6.67394;,
 0.00000;1.80490;9.43836;,
 -6.67394;1.80490;6.67394;,
 -9.43836;1.80490;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 0.00000;0.25932;0.00000;,
 -8.14487;27.18436;-21.86194;,
 -8.45643;25.78431;-23.02465;,
 -11.40963;25.78431;-20.98714;,
 -8.14487;27.18436;-21.86194;,
 -4.88012;25.78431;-22.73673;,
 -8.14487;27.18436;-21.86194;,
 -7.83333;25.78431;-20.69922;,
 -8.14487;27.18436;-21.86194;,
 -11.40963;25.78431;-20.98714;,
 -8.58547;22.40441;-23.50627;,
 -12.76194;22.40441;-20.62479;,
 -3.52781;22.40441;-23.09906;,
 -7.70428;22.40441;-20.21762;,
 -12.76194;22.40441;-20.62479;,
 -8.45643;19.02447;-23.02465;,
 -11.40963;19.02447;-20.98714;,
 -4.88012;19.02447;-22.73673;,
 -7.83333;19.02447;-20.69922;,
 -11.40963;19.02447;-20.98714;,
 -8.14487;17.62447;-21.86194;,
 -8.14487;17.62447;-21.86194;,
 -8.14487;17.62447;-21.86194;,
 -8.14487;17.62447;-21.86194;,
 9.35389;27.18436;-21.86194;,
 9.58358;25.78431;-23.04355;,
 6.03606;25.78431;-22.50683;,
 9.35389;27.18436;-21.86194;,
 12.67171;25.78431;-21.21701;,
 9.35389;27.18436;-21.86194;,
 9.12419;25.78431;-20.68031;,
 9.35389;27.18436;-21.86194;,
 6.03606;25.78431;-22.50683;,
 9.67871;22.40441;-23.53299;,
 4.66175;22.40441;-22.77398;,
 14.04598;22.40441;-20.94988;,
 9.02907;22.40441;-20.19088;,
 4.66175;22.40441;-22.77398;,
 9.58358;19.02447;-23.04355;,
 6.03606;19.02447;-22.50683;,
 12.67171;19.02447;-21.21701;,
 9.12419;19.02447;-20.68031;,
 6.03606;19.02447;-22.50683;,
 9.35389;17.62447;-21.86194;,
 9.35389;17.62447;-21.86194;,
 9.35389;17.62447;-21.86194;,
 9.35389;17.62447;-21.86194;;
 
 120;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;1,18,19,2;,
 4;2,19,20,4;,
 4;4,20,21,6;,
 4;6,21,22,8;,
 4;8,22,23,10;,
 4;10,23,24,12;,
 4;12,24,25,14;,
 4;14,25,26,16;,
 3;18,27,19;,
 3;19,28,20;,
 3;20,29,21;,
 3;21,30,22;,
 3;22,31,23;,
 3;23,32,24;,
 3;24,33,25;,
 3;25,34,26;,
 3;35,36,37;,
 3;38,39,36;,
 3;40,41,39;,
 3;42,43,41;,
 3;44,45,43;,
 3;46,47,45;,
 3;48,49,47;,
 3;50,51,49;,
 4;37,36,52,53;,
 4;36,39,54,52;,
 4;39,41,55,54;,
 4;41,43,56,55;,
 4;43,45,57,56;,
 4;45,47,58,57;,
 4;47,49,59,58;,
 4;49,51,60,59;,
 4;53,52,61,62;,
 4;52,54,63,61;,
 4;54,55,64,63;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;62,61,70,71;,
 4;61,63,72,70;,
 4;63,64,73,72;,
 4;64,65,74,73;,
 4;65,66,75,74;,
 4;66,67,76,75;,
 4;67,68,77,76;,
 4;68,69,78,77;,
 4;71,70,79,80;,
 4;70,72,81,79;,
 4;72,73,82,81;,
 4;73,74,83,82;,
 4;74,75,84,83;,
 4;75,76,85,84;,
 4;76,77,86,85;,
 4;77,78,87,86;,
 4;80,79,88,89;,
 4;79,81,90,88;,
 4;81,82,91,90;,
 4;82,83,92,91;,
 4;83,84,93,92;,
 4;84,85,94,93;,
 4;85,86,95,94;,
 4;86,87,96,95;,
 4;89,88,97,98;,
 4;88,90,99,97;,
 4;90,91,100,99;,
 4;91,92,101,100;,
 4;92,93,102,101;,
 4;93,94,103,102;,
 4;94,95,104,103;,
 4;95,96,105,104;,
 3;98,97,106;,
 3;97,99,107;,
 3;99,100,108;,
 3;100,101,109;,
 3;101,102,110;,
 3;102,103,111;,
 3;103,104,112;,
 3;104,105,113;,
 3;114,115,116;,
 3;117,118,115;,
 3;119,120,118;,
 3;121,122,120;,
 4;116,115,123,124;,
 4;115,118,125,123;,
 4;118,120,126,125;,
 4;120,122,127,126;,
 4;124,123,128,129;,
 4;123,125,130,128;,
 4;125,126,131,130;,
 4;126,127,132,131;,
 3;129,128,133;,
 3;128,130,134;,
 3;130,131,135;,
 3;131,132,136;,
 3;137,138,139;,
 3;140,141,138;,
 3;142,143,141;,
 3;144,145,143;,
 4;139,138,146,147;,
 4;138,141,148,146;,
 4;141,143,149,148;,
 4;143,145,150,149;,
 4;147,146,151,152;,
 4;146,148,153,151;,
 4;148,149,154,153;,
 4;149,150,155,154;,
 3;152,151,156;,
 3;151,153,157;,
 3;153,154,158;,
 3;154,155,159;;
 
 MeshMaterialList {
  3;
  120;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.000000;0.062400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.235200;0.213600;0.235200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.793600;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  131;
  -0.000000;0.939965;-0.341270;,
  0.206475;0.947448;-0.244355;,
  0.283719;0.958907;0.000000;,
  0.206475;0.947448;0.244355;,
  -0.000000;0.939965;0.341270;,
  -0.206475;0.947448;0.244355;,
  -0.283719;0.958907;-0.000000;,
  -0.206475;0.947448;-0.244355;,
  -0.000000;0.778556;-0.627576;,
  0.436640;0.777057;-0.453353;,
  0.643628;0.765329;0.003885;,
  0.473058;0.726695;0.498127;,
  -0.000000;0.706194;0.708019;,
  -0.473058;0.726695;0.498126;,
  -0.643628;0.765329;0.003884;,
  -0.436640;0.777057;-0.453353;,
  -0.019622;0.691160;-0.722436;,
  0.497878;0.716402;-0.488759;,
  0.799003;0.600338;0.034474;,
  0.679245;0.231106;0.696575;,
  0.030064;-0.182662;0.982716;,
  -0.660875;0.343652;0.667194;,
  -0.956473;0.259014;-0.134428;,
  -0.659522;0.442769;-0.607443;,
  0.345821;0.893490;-0.286503;,
  -0.212584;-0.722468;0.657912;,
  -0.467221;-0.759640;0.452384;,
  -0.651947;-0.708549;0.270045;,
  -0.921011;-0.078739;-0.381495;,
  0.000000;1.000000;0.000000;,
  -0.325099;0.945680;0.000000;,
  -0.229880;0.945680;-0.229880;,
  0.000000;0.945680;-0.325099;,
  0.229880;0.945680;-0.229880;,
  0.325099;0.945680;0.000000;,
  0.229880;0.945680;0.229880;,
  0.000000;0.945680;0.325099;,
  -0.229880;0.945680;0.229880;,
  -0.638882;0.769305;-0.000000;,
  -0.451758;0.769305;-0.451758;,
  0.000000;0.769305;-0.638882;,
  0.451758;0.769305;-0.451758;,
  0.638882;0.769305;-0.000000;,
  0.451757;0.769305;0.451758;,
  0.000000;0.769305;0.638882;,
  -0.451758;0.769305;0.451758;,
  -0.894997;0.446072;-0.000000;,
  -0.632859;0.446072;-0.632859;,
  0.000000;0.446072;-0.894997;,
  0.632859;0.446072;-0.632859;,
  0.894997;0.446072;-0.000000;,
  0.632858;0.446072;0.632859;,
  0.000000;0.446072;0.894997;,
  -0.632858;0.446072;0.632859;,
  -1.000000;0.000002;-0.000000;,
  -0.707107;0.000002;-0.707107;,
  0.000000;0.000002;-1.000000;,
  0.707107;0.000002;-0.707107;,
  1.000000;0.000002;-0.000000;,
  0.707107;0.000002;0.707107;,
  0.000000;0.000002;1.000000;,
  -0.707107;0.000002;0.707107;,
  -0.894998;-0.446070;-0.000000;,
  -0.632859;-0.446070;-0.632859;,
  0.000000;-0.446070;-0.894998;,
  0.632859;-0.446070;-0.632859;,
  0.894998;-0.446070;-0.000000;,
  0.632859;-0.446070;0.632859;,
  0.000000;-0.446070;0.894998;,
  -0.632859;-0.446070;0.632859;,
  -0.638881;-0.769306;-0.000000;,
  -0.451757;-0.769306;-0.451757;,
  0.000000;-0.769306;-0.638881;,
  0.451757;-0.769306;-0.451757;,
  0.638881;-0.769306;-0.000000;,
  0.451757;-0.769306;0.451757;,
  0.000000;-0.769306;0.638880;,
  -0.451757;-0.769306;0.451757;,
  -0.325098;-0.945680;0.000000;,
  -0.229879;-0.945680;-0.229879;,
  0.000000;-0.945680;-0.325098;,
  0.229879;-0.945680;-0.229879;,
  0.325098;-0.945680;-0.000000;,
  0.229879;-0.945680;0.229879;,
  0.000000;-0.945680;0.325098;,
  -0.229879;-0.945680;0.229879;,
  0.000000;-1.000000;-0.000000;,
  -0.196254;0.651944;-0.732430;,
  -0.520949;0.398088;-0.755074;,
  -0.235076;0.418396;-0.877316;,
  0.073618;0.398087;-0.914389;,
  0.235077;0.418396;0.877316;,
  -0.567887;0.000001;-0.823107;,
  -0.258819;0.000001;-0.965926;,
  0.080252;0.000001;-0.996775;,
  0.258819;0.000001;0.965926;,
  -0.520948;-0.398095;-0.755072;,
  -0.235075;-0.418402;-0.877313;,
  0.073618;-0.398093;-0.914387;,
  0.235076;-0.418403;0.877313;,
  -0.196252;-0.651955;-0.732421;,
  0.196255;0.651945;0.732429;,
  0.520948;0.398088;0.755076;,
  -0.073615;0.398088;0.914389;,
  0.567884;0.000001;0.823108;,
  -0.080248;0.000001;0.996775;,
  0.520946;-0.398094;0.755074;,
  -0.073615;-0.398094;0.914386;,
  0.196252;-0.651956;0.732420;,
  0.144683;0.651942;-0.744338;,
  -0.137226;0.398087;-0.907026;,
  0.173304;0.418396;-0.891578;,
  0.467010;0.398086;-0.789575;,
  -0.173304;0.418399;0.891576;,
  -0.149589;0.000001;-0.988748;,
  0.190809;0.000001;-0.981627;,
  0.509088;0.000001;-0.860715;,
  -0.190808;0.000001;0.981627;,
  -0.137226;-0.398094;-0.907023;,
  0.173304;-0.418402;-0.891575;,
  0.467009;-0.398092;-0.789573;,
  -0.173303;-0.418405;0.891573;,
  0.144682;-0.651953;-0.744328;,
  -0.144682;0.651951;0.744330;,
  0.137223;0.398089;0.907025;,
  -0.467006;0.398092;0.789575;,
  0.149586;0.000001;0.988749;,
  -0.509083;0.000001;0.860717;,
  0.137222;-0.398096;0.907023;,
  -0.467005;-0.398098;0.789573;,
  -0.144680;-0.651962;0.744320;;
  120;
  4;0,8,9,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,8,0;,
  4;8,16,17,9;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,16,8;,
  3;16,24,17;,
  3;17,24,18;,
  3;18,24,19;,
  3;19,25,20;,
  3;20,25,26;,
  3;26,25,27;,
  3;22,28,23;,
  3;23,24,16;,
  3;29,31,30;,
  3;29,32,31;,
  3;29,33,32;,
  3;29,34,33;,
  3;29,35,34;,
  3;29,36,35;,
  3;29,37,36;,
  3;29,30,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,33,41,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,30,38,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,38,46,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  4;49,50,58,57;,
  4;50,51,59,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,46,54,61;,
  4;54,55,63,62;,
  4;55,56,64,63;,
  4;56,57,65,64;,
  4;57,58,66,65;,
  4;58,59,67,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,54,62,69;,
  4;62,63,71,70;,
  4;63,64,72,71;,
  4;64,65,73,72;,
  4;65,66,74,73;,
  4;66,67,75,74;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,62,70,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;76,77,85,84;,
  4;77,70,78,85;,
  3;78,79,86;,
  3;79,80,86;,
  3;80,81,86;,
  3;81,82,86;,
  3;82,83,86;,
  3;83,84,86;,
  3;84,85,86;,
  3;85,78,86;,
  3;87,89,88;,
  3;87,90,89;,
  3;101,91,102;,
  3;101,103,91;,
  4;88,89,93,92;,
  4;89,90,94,93;,
  4;102,91,95,104;,
  4;91,103,105,95;,
  4;92,93,97,96;,
  4;93,94,98,97;,
  4;104,95,99,106;,
  4;95,105,107,99;,
  3;96,97,100;,
  3;97,98,100;,
  3;106,99,108;,
  3;99,107,108;,
  3;109,111,110;,
  3;109,112,111;,
  3;123,113,124;,
  3;123,125,113;,
  4;110,111,115,114;,
  4;111,112,116,115;,
  4;124,113,117,126;,
  4;113,125,127,117;,
  4;114,115,119,118;,
  4;115,116,120,119;,
  4;126,117,121,128;,
  4;117,127,129,121;,
  3;118,119,122;,
  3;119,120,122;,
  3;128,121,130;,
  3;121,129,130;;
 }
 MeshTextureCoords {
  160;
  0.000000;1.000000;,
  0.000000;0.666667;,
  0.125000;0.666667;,
  0.125000;1.000000;,
  0.250000;0.666667;,
  0.250000;1.000000;,
  0.375000;0.666667;,
  0.375000;1.000000;,
  0.500000;0.666667;,
  0.500000;1.000000;,
  0.625000;0.666667;,
  0.625000;1.000000;,
  0.750000;0.666667;,
  0.750000;1.000000;,
  0.875000;0.666667;,
  0.875000;1.000000;,
  1.000000;0.666667;,
  1.000000;1.000000;,
  0.000000;0.333333;,
  0.125000;0.333333;,
  0.250000;0.333333;,
  0.375000;0.333333;,
  0.500000;0.333333;,
  0.625000;0.333333;,
  0.750000;0.333333;,
  0.875000;0.333333;,
  1.000000;0.333333;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.125000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.125000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.125000;1.000000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.875000;1.000000;;
 }
}