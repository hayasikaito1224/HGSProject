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
 329;
 4.04958;3.31599;-38.07510;,
 4.81084;15.31048;-20.63961;,
 5.03278;7.90735;-15.55645;,
 4.27152;-4.08714;-32.99193;,
 3.43944;23.60342;-0.56464;,
 -4.16358;15.31048;-20.24783;,
 -3.94168;7.90735;-15.16462;,
 -3.18042;19.90185;2.27080;,
 -4.92488;3.31599;-37.68334;,
 -4.70294;-4.08714;-32.60006;,
 -4.16358;15.31048;-20.24783;,
 4.81084;15.31048;-20.63961;,
 4.04958;3.31599;-38.07510;,
 -4.92488;3.31599;-37.68334;,
 -18.85059;3.31599;-34.54981;,
 -7.74972;15.31048;-21.08338;,
 -4.51332;7.90735;-17.15734;,
 -15.61423;-4.08714;-30.62374;,
 -0.11461;27.30498;-4.76000;,
 6.58759;19.90185;-3.69084;,
 -0.11461;27.30498;-4.76000;,
 -14.68118;15.31048;-15.36952;,
 -11.44483;7.90735;-11.44344;,
 -0.34396;19.90185;2.02305;,
 -25.78214;3.31599;-28.83592;,
 -22.54575;-4.08714;-24.90985;,
 -14.68118;15.31048;-15.36952;,
 -7.74972;15.31048;-21.08338;,
 -18.85059;3.31599;-34.54981;,
 -25.78214;3.31599;-28.83592;,
 -35.09739;3.31599;-11.31963;,
 -17.68783;15.31048;-10.10227;,
 -12.61219;7.90735;-9.74736;,
 -30.02170;-4.08714;-10.96472;,
 -0.59158;27.30498;-4.40429;,
 4.79742;19.90185;-8.52994;,
 -0.59158;27.30498;-4.40429;,
 -18.31446;15.31048;-1.14117;,
 -13.23881;7.90735;-0.78622;,
 4.17077;19.90185;0.43119;,
 -35.72402;3.31599;-2.35850;,
 -30.64841;-4.08714;-2.00359;,
 -18.31446;15.31048;-1.14117;,
 -17.68783;15.31048;-10.10227;,
 -35.09739;3.31599;-11.31963;,
 -35.72402;3.31599;-2.35850;,
 -34.61678;3.31599;12.65710;,
 -20.06377;15.31048;3.02469;,
 -15.82092;7.90735;0.21637;,
 -30.37394;-4.08714;9.84887;,
 -3.03173;27.30498;-2.86239;,
 -1.26784;19.90185;-9.41608;,
 -3.03173;27.30498;-2.86239;,
 -15.10572;15.31048;10.51549;,
 -10.86287;7.90735;7.70717;,
 3.69017;19.90185;-1.92524;,
 -29.65876;3.31599;20.14795;,
 -25.41593;-4.08714;17.33967;,
 -15.10572;15.31048;10.51549;,
 -20.06377;15.31048;3.02469;,
 -34.61678;3.31599;12.65710;,
 -29.65876;3.31599;20.14795;,
 -20.73103;3.31599;31.81906;,
 -13.08053;15.31048;16.13323;,
 -10.85009;7.90735;11.56012;,
 -18.50057;-4.08714;27.24593;,
 -1.39312;27.30498;2.41634;,
 -3.19957;19.90185;-4.12574;,
 -1.39312;27.30498;2.41634;,
 -5.00670;15.31048;20.07111;,
 -2.77622;7.90735;15.49802;,
 4.87430;19.90185;-0.18783;,
 -12.65714;3.31599;35.75699;,
 -10.42671;-4.08714;31.18384;,
 -5.00670;15.31048;20.07111;,
 -13.08053;15.31048;16.13323;,
 -20.73103;3.31599;31.81906;,
 -12.65714;3.31599;35.75699;,
 2.14855;3.31599;36.24225;,
 -0.28034;15.31048;18.95999;,
 -0.98845;7.90735;13.92143;,
 1.44043;-4.08714;31.20366;,
 1.73862;27.30498;1.05267;,
 -3.41733;19.90185;-3.36085;,
 1.73862;27.30498;1.05267;,
 8.61526;15.31048;17.70982;,
 7.90715;7.90735;12.67126;,
 5.47830;19.90185;-4.61098;,
 11.04414;3.31599;34.99204;,
 10.33599;-4.08714;29.95349;,
 8.61526;15.31048;17.70982;,
 -0.28034;15.31048;18.95999;,
 2.14855;3.31599;36.24225;,
 11.04414;3.31599;34.99204;,
 25.28581;3.31599;26.90810;,
 12.11453;15.31048;15.45853;,
 8.27451;7.90735;12.12046;,
 21.44574;-4.08714;23.57002;,
 1.88998;27.30498;0.61913;,
 -1.95008;19.90185;-2.71895;,
 1.88998;27.30498;0.61913;,
 18.00789;15.31048;8.67895;,
 14.16788;7.90735;5.34091;,
 -1.95008;19.90185;-2.71895;,
 31.17921;3.31599;20.12854;,
 27.33913;-4.08714;16.79048;,
 18.00789;15.31048;8.67895;,
 12.11453;15.31048;15.45853;,
 25.28581;3.31599;26.90810;,
 31.17921;3.31599;20.12854;,
 36.60317;3.31599;3.81772;,
 19.15371;15.31048;3.51313;,
 14.06644;7.90735;3.42434;,
 31.51587;-4.08714;3.72890;,
 1.78269;27.30498;-1.28226;,
 -3.38302;19.90185;3.11975;,
 1.78269;27.30498;-1.28226;,
 19.31049;15.31048;-5.46851;,
 14.22323;7.90735;-5.55732;,
 -3.22620;19.90185;-5.86191;,
 36.75996;3.31599;-5.16395;,
 31.67263;-4.08714;-5.25273;,
 19.31049;15.31048;-5.46851;,
 19.15371;15.31048;3.51313;,
 36.60317;3.31599;3.81772;,
 36.75996;3.31599;-5.16395;,
 35.90494;3.31599;-17.04850;,
 21.26836;15.31048;-7.54336;,
 17.00112;7.90735;-4.77222;,
 31.63773;-4.08714;-14.27732;,
 4.18553;27.30498;-1.80517;,
 2.36460;19.90185;4.73288;,
 4.18553;27.30498;-1.80517;,
 16.37582;15.31048;-15.07715;,
 12.10864;7.90735;-12.30602;,
 -2.52789;19.90185;-2.80095;,
 31.01243;3.31599;-24.58230;,
 26.74522;-4.08714;-21.81112;,
 16.37582;15.31048;-15.07715;,
 21.26836;15.31048;-7.54336;,
 35.90494;3.31599;-17.04850;,
 31.01243;3.31599;-24.58230;,
 23.04647;3.31599;-31.83639;,
 15.12338;15.31048;-16.28644;,
 12.81344;7.90735;-11.75297;,
 20.73651;-4.08714;-27.30291;,
 3.19835;27.30498;-2.77564;,
 4.89038;19.90185;3.79693;,
 3.19835;27.30498;-2.77564;,
 7.11946;15.31048;-20.36463;,
 4.80952;7.90735;-15.83117;,
 -3.11354;19.90185;-0.28130;,
 15.04252;3.31599;-35.91462;,
 12.73259;-4.08714;-31.38110;,
 7.11946;15.31048;-20.36463;,
 15.12338;15.31048;-16.28644;,
 23.04647;3.31599;-31.83639;,
 15.04252;3.31599;-35.91462;,
 4.18553;27.30498;-1.80517;,
 -2.52789;19.90185;-2.80095;,
 2.36460;19.90185;4.73288;,
 1.73862;27.30498;1.05267;,
 5.47830;19.90185;-4.61098;,
 -3.41733;19.90185;-3.36085;,
 1.88998;27.30498;0.61913;,
 3.19835;27.30498;-2.77564;,
 -3.11354;19.90185;-0.28130;,
 4.89038;19.90185;3.79693;,
 -0.11461;27.30498;-4.76000;,
 -0.34396;19.90185;2.02305;,
 6.58759;19.90185;-3.69084;,
 3.43944;23.60342;-0.56464;,
 1.78269;27.30498;-1.28226;,
 -3.22620;19.90185;-5.86191;,
 -3.38302;19.90185;3.11975;,
 -0.59158;27.30498;-4.40429;,
 4.17077;19.90185;0.43119;,
 4.79742;19.90185;-8.52994;,
 -3.03173;27.30498;-2.86239;,
 3.69017;19.90185;-1.92524;,
 -1.26784;19.90185;-9.41608;,
 -1.39312;27.30498;2.41634;,
 4.87430;19.90185;-0.18783;,
 -3.19957;19.90185;-4.12574;,
 3.43944;23.60342;-0.56464;,
 11.15012;6.98502;-45.62785;,
 11.15016;6.98502;-37.46672;,
 11.15016;-1.17615;-37.46672;,
 11.15012;-1.17615;-45.62785;,
 11.15016;6.98502;-37.46672;,
 -14.32864;6.98502;-37.46672;,
 -14.32864;-1.17615;-37.46672;,
 11.15016;-1.17615;-37.46672;,
 -14.32864;6.98502;-37.46672;,
 -14.32864;6.98502;-45.62791;,
 -14.32864;-1.17615;-45.62791;,
 -14.32864;-1.17615;-37.46672;,
 -14.32864;6.98502;-45.62791;,
 11.15012;6.98502;-45.62785;,
 11.15012;-1.17615;-45.62785;,
 -14.32864;-1.17615;-45.62791;,
 11.15016;6.98502;-37.46672;,
 11.15012;6.98502;-45.62785;,
 -22.05706;6.98502;-42.84858;,
 -16.92106;6.98502;-36.50623;,
 -16.92106;-1.17615;-36.50623;,
 -22.05706;-1.17615;-42.84858;,
 -16.92106;6.98502;-36.50623;,
 -36.72176;6.98502;-20.47186;,
 -36.72176;-1.17615;-20.47186;,
 -16.92106;-1.17615;-36.50623;,
 -36.72176;6.98502;-20.47186;,
 -41.85779;6.98502;-26.81426;,
 -41.85779;-1.17615;-26.81426;,
 -36.72176;-1.17615;-20.47186;,
 -41.85779;6.98502;-26.81426;,
 -22.05706;6.98502;-42.84858;,
 -22.05706;-1.17615;-42.84858;,
 -41.85779;-1.17615;-26.81426;,
 -16.92106;6.98502;-36.50623;,
 -22.05706;6.98502;-42.84858;,
 -45.31992;6.98502;-15.98516;,
 -37.16992;6.98502;-16.41229;,
 -37.16992;-1.17615;-16.41229;,
 -45.31992;-1.17615;-15.98516;,
 -37.16992;6.98502;-16.41229;,
 -35.83648;6.98502;9.03155;,
 -35.83648;-1.17615;9.03155;,
 -37.16992;-1.17615;-16.41229;,
 -35.83648;6.98502;9.03155;,
 -43.98639;6.98502;9.45867;,
 -43.98639;-1.17615;9.45867;,
 -35.83648;-1.17615;9.03155;,
 -43.98639;6.98502;9.45867;,
 -45.31992;6.98502;-15.98516;,
 -45.31992;-1.17615;-15.98516;,
 -43.98639;-1.17615;9.45867;,
 -37.16992;6.98502;-16.41229;,
 -45.31992;6.98502;-15.98516;,
 -41.16675;6.98502;19.65457;,
 -34.69206;6.98502;14.68637;,
 -34.69206;-1.17615;14.68637;,
 -41.16675;-1.17615;19.65457;,
 -34.69206;6.98502;14.68637;,
 -19.18157;6.98502;34.90001;,
 -19.18157;-1.17615;34.90001;,
 -34.69206;-1.17615;14.68637;,
 -19.18157;6.98502;34.90001;,
 -25.65624;6.98502;39.86819;,
 -25.65624;-1.17615;39.86819;,
 -19.18157;-1.17615;34.90001;,
 -25.65624;6.98502;39.86819;,
 -41.16675;6.98502;19.65457;,
 -41.16675;-1.17615;19.65457;,
 -25.65624;-1.17615;39.86819;,
 -34.69206;6.98502;14.68637;,
 -41.16675;6.98502;19.65457;,
 -13.96603;6.98502;45.21523;,
 -14.10850;6.98502;37.05529;,
 -14.10850;-1.17615;37.05529;,
 -13.96603;-1.17615;45.21523;,
 -14.10850;6.98502;37.05529;,
 11.36642;6.98502;36.61062;,
 11.36642;-1.17615;36.61062;,
 -14.10850;-1.17615;37.05529;,
 11.36642;6.98502;36.61062;,
 11.50882;6.98502;44.77053;,
 11.50882;-1.17615;44.77053;,
 11.36642;-1.17615;36.61062;,
 11.50882;6.98502;44.77053;,
 -13.96603;6.98502;45.21523;,
 -13.96603;-1.17615;45.21523;,
 11.50882;-1.17615;44.77053;,
 -14.10850;6.98502;37.05529;,
 -13.96603;6.98502;45.21523;,
 20.60636;6.98502;42.05771;,
 15.30603;6.98502;35.85192;,
 15.30603;-1.17615;35.85192;,
 20.60636;-1.17615;42.05771;,
 15.30603;6.98502;35.85192;,
 34.68025;6.98502;19.30474;,
 34.68025;-1.17615;19.30474;,
 15.30603;-1.17615;35.85192;,
 34.68025;6.98502;19.30474;,
 39.98053;6.98502;25.51056;,
 39.98053;-1.17615;25.51056;,
 34.68025;-1.17615;19.30474;,
 39.98053;6.98502;25.51056;,
 20.60636;6.98502;42.05771;,
 20.60636;-1.17615;42.05771;,
 39.98053;-1.17615;25.51056;,
 15.30603;6.98502;35.85192;,
 20.60636;6.98502;42.05771;,
 45.05264;6.98502;15.01712;,
 36.90268;6.98502;14.59007;,
 36.90268;-1.17615;14.59007;,
 45.05264;-1.17615;15.01712;,
 36.90268;6.98502;14.59007;,
 38.23611;6.98502;-10.85377;,
 38.23611;-1.17615;-10.85377;,
 36.90268;-1.17615;14.59007;,
 38.23611;6.98502;-10.85377;,
 46.38614;6.98502;-10.42663;,
 46.38614;-1.17615;-10.42663;,
 38.23611;-1.17615;-10.85377;,
 46.38614;6.98502;-10.42663;,
 45.05264;6.98502;15.01712;,
 45.05264;-1.17615;15.01712;,
 46.38614;-1.17615;-10.42663;,
 36.90268;6.98502;14.59007;,
 45.05264;6.98502;15.01712;,
 42.62772;6.98502;-24.30814;,
 36.95858;6.98502;-18.43741;,
 36.95858;-1.17615;-18.43741;,
 42.62772;-1.17615;-24.30814;,
 36.95858;6.98502;-18.43741;,
 18.63069;6.98502;-36.13645;,
 18.63069;-1.17615;-36.13645;,
 36.95858;-1.17615;-18.43741;,
 18.63069;6.98502;-36.13645;,
 24.29992;6.98502;-42.00712;,
 24.29992;-1.17615;-42.00712;,
 18.63069;-1.17615;-36.13645;,
 24.29992;6.98502;-42.00712;,
 42.62772;6.98502;-24.30814;,
 42.62772;-1.17615;-24.30814;,
 24.29992;-1.17615;-42.00712;,
 36.95858;6.98502;-18.43741;,
 42.62772;6.98502;-24.30814;;
 
 108;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;5,8,9,6;,
 4;10,11,12,13;,
 4;14,15,16,17;,
 4;15,18,19,16;,
 4;20,21,22,23;,
 4;21,24,25,22;,
 4;26,27,28,29;,
 4;30,31,32,33;,
 4;31,34,35,32;,
 4;36,37,38,39;,
 4;37,40,41,38;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;47,50,51,48;,
 4;52,53,54,55;,
 4;53,56,57,54;,
 4;58,59,60,61;,
 4;62,63,64,65;,
 4;63,66,67,64;,
 4;68,69,70,71;,
 4;69,72,73,70;,
 4;74,75,76,77;,
 4;78,79,80,81;,
 4;79,82,83,80;,
 4;84,85,86,87;,
 4;85,88,89,86;,
 4;90,91,92,93;,
 4;94,95,96,97;,
 4;95,98,99,96;,
 4;100,101,102,103;,
 4;101,104,105,102;,
 4;106,107,108,109;,
 4;110,111,112,113;,
 4;111,114,115,112;,
 4;116,117,118,119;,
 4;117,120,121,118;,
 4;122,123,124,125;,
 4;126,127,128,129;,
 4;127,130,131,128;,
 4;132,133,134,135;,
 4;133,136,137,134;,
 4;138,139,140,141;,
 4;142,143,144,145;,
 4;143,146,147,144;,
 4;148,149,150,151;,
 4;149,152,153,150;,
 4;154,155,156,157;,
 3;158,159,160;,
 3;158,139,138;,
 3;161,162,163;,
 3;161,91,90;,
 3;164,107,106;,
 3;165,166,167;,
 3;165,155,154;,
 3;168,169,170;,
 3;168,27,26;,
 3;171,11,10;,
 3;172,173,174;,
 3;172,123,122;,
 3;175,176,177;,
 3;175,43,42;,
 3;178,179,180;,
 3;178,59,58;,
 3;181,182,183;,
 3;181,75,74;,
 3;184,2,1;,
 4;185,186,187,188;,
 4;189,190,191,192;,
 4;193,194,195,196;,
 4;197,198,199,200;,
 4;197,190,201,202;,
 4;203,204,205,206;,
 4;207,208,209,210;,
 4;211,212,213,214;,
 4;215,216,217,218;,
 4;215,208,219,220;,
 4;221,222,223,224;,
 4;225,226,227,228;,
 4;229,230,231,232;,
 4;233,234,235,236;,
 4;233,226,237,238;,
 4;239,240,241,242;,
 4;243,244,245,246;,
 4;247,248,249,250;,
 4;251,252,253,254;,
 4;251,244,255,256;,
 4;257,258,259,260;,
 4;261,262,263,264;,
 4;265,266,267,268;,
 4;269,270,271,272;,
 4;269,262,273,274;,
 4;275,276,277,278;,
 4;279,280,281,282;,
 4;283,284,285,286;,
 4;287,288,289,290;,
 4;287,280,291,292;,
 4;293,294,295,296;,
 4;297,298,299,300;,
 4;301,302,303,304;,
 4;305,306,307,308;,
 4;305,298,309,310;,
 4;311,312,313,314;,
 4;315,316,317,318;,
 4;319,320,321,322;,
 4;323,324,325,326;,
 4;323,316,327,328;;
 
 MeshMaterialList {
  3;
  108;
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
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
   0.605600;0.228800;0.097600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.200800;0.109600;0.065600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.357600;0.357600;0.357600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  131;
  -0.999048;0.000002;0.043620;,
  0.999048;0.000001;-0.043620;,
  0.999553;0.029908;-0.000085;,
  -0.866956;0.490389;-0.088909;,
  -0.966893;0.254102;-0.023467;,
  -0.771624;0.000004;0.636079;,
  0.771624;-0.000001;-0.636079;,
  0.749911;0.121571;-0.650272;,
  0.716610;0.241264;-0.654418;,
  -0.781415;0.121573;0.612054;,
  -0.779132;0.241263;0.578572;,
  -0.069755;0.000002;0.997564;,
  0.069755;0.000000;-0.997564;,
  0.044513;0.121572;-0.991584;,
  0.018584;0.241264;-0.970282;,
  -0.093921;0.121572;0.988129;,
  -0.116636;0.241262;0.963425;,
  0.551939;-0.000001;0.833885;,
  -0.551938;-0.000001;-0.833885;,
  -0.568323;0.121570;-0.813775;,
  -0.575927;0.241263;-0.781089;,
  0.527023;0.121570;0.841111;,
  0.493965;0.241262;0.835339;,
  0.898795;0.000000;0.438370;,
  -0.898794;0.000001;-0.438371;,
  -0.902705;0.121571;-0.412727;,
  -0.892668;0.241262;-0.380705;,
  0.880994;0.121571;0.457242;,
  0.849580;0.241264;0.469048;,
  0.990268;-0.000001;-0.139174;,
  -0.990268;-0.000002;0.139173;,
  -0.979171;0.121570;0.162621;,
  -0.952943;0.241262;0.183555;,
  0.986064;0.121571;-0.113575;,
  0.966622;0.241263;-0.086221;,
  0.656056;-0.000002;-0.754712;,
  -0.656058;0.000001;0.754711;,
  -0.717358;0.059084;0.694195;,
  -0.770831;0.117522;0.626106;,
  0.587600;0.059080;-0.806992;,
  0.017452;0.000000;-0.999848;,
  -0.017452;-0.000000;0.999848;,
  0.007443;0.121571;0.992555;,
  0.032222;0.241263;0.969925;,
  0.042078;0.121572;-0.991690;,
  0.066054;0.241264;-0.968209;,
  -0.544639;-0.000000;-0.838670;,
  0.544639;-0.000000;0.838671;,
  0.561199;0.121570;0.818704;,
  0.569088;0.241262;0.786086;,
  -0.519662;0.121571;-0.845678;,
  -0.486655;0.241264;-0.839618;,
  -0.891007;0.000001;-0.453990;,
  0.891006;-0.000002;0.453991;,
  0.895365;0.121569;0.428419;,
  0.885888;0.241262;0.396226;,
  -0.872880;0.121572;-0.472548;,
  -0.841264;0.241264;-0.483804;,
  -0.020819;0.878712;-0.476898;,
  -0.024702;0.824126;-0.565867;,
  -0.360279;0.824126;-0.437054;,
  -0.360279;0.824126;-0.437054;,
  -0.565027;0.824126;-0.039511;,
  -0.565027;0.824126;-0.039511;,
  -0.472319;0.824126;0.312620;,
  -0.472320;0.824126;0.312620;,
  -0.248297;0.824126;0.509082;,
  -0.248297;0.824126;0.509082;,
  0.078828;0.824126;0.560895;,
  0.078828;0.824126;0.560894;,
  0.512733;0.117518;-0.850467;,
  0.427473;0.824126;0.371595;,
  0.427472;0.824126;0.371595;,
  0.566320;0.824126;0.009885;,
  0.566319;0.824127;0.009885;,
  0.475027;0.824127;-0.308488;,
  0.475026;0.824127;-0.308487;,
  0.257143;0.824126;-0.504672;,
  0.257143;0.824127;-0.504671;,
  -0.691173;0.566406;0.448849;,
  0.475027;0.824126;-0.308489;,
  -0.114689;0.566412;-0.816103;,
  0.078827;0.824126;0.560895;,
  0.427474;0.824126;0.371595;,
  -0.374148;0.566406;0.734301;,
  0.257143;0.824126;-0.504673;,
  0.524205;0.566411;0.635915;,
  -0.360280;0.824125;-0.437054;,
  -0.016708;0.923711;-0.382725;,
  -0.823998;0.566409;-0.014387;,
  0.566321;0.824126;0.009885;,
  0.822117;0.566409;0.057491;,
  -0.565027;0.824126;-0.039511;,
  0.687228;0.566410;-0.454860;,
  -0.472319;0.824126;0.312621;,
  0.361273;0.566410;-0.740717;,
  -0.248297;0.824126;0.509083;,
  0.997268;0.059733;0.043452;,
  1.000000;0.000000;-0.000005;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.777142;0.000000;-0.629325;,
  0.629322;0.000000;0.777145;,
  -0.777142;0.000000;0.629325;,
  -0.052336;0.000000;-0.998630;,
  0.998630;0.000000;-0.052335;,
  0.052337;0.000000;0.998629;,
  -0.608761;0.000000;-0.793354;,
  0.793353;0.000000;-0.608762;,
  0.608762;0.000000;0.793353;,
  -0.999848;0.000000;0.017458;,
  -0.017452;0.000000;-0.999848;,
  0.999848;0.000000;-0.017449;,
  -0.760400;0.000000;0.649455;,
  -0.649449;0.000000;-0.760405;,
  0.760405;0.000000;-0.649449;,
  -0.052327;0.000000;0.998630;,
  -0.998630;0.000000;-0.052335;,
  0.052338;0.000000;-0.998629;,
  0.719349;0.000000;0.694648;,
  -0.694659;0.000000;0.719340;,
  -0.719340;0.000000;-0.694658;,
  0.000002;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  -0.629321;0.000000;-0.777146;,
  -0.998629;0.000000;0.052339;,
  -0.793352;0.000000;0.608763;,
  0.017454;0.000000;0.999848;,
  0.649449;0.000000;0.760405;,
  0.998630;0.000000;0.052338;,
  0.694659;0.000000;-0.719339;;
  108;
  4;1,2,2,1;,
  4;3,4,4,3;,
  4;4,0,0,4;,
  4;58,58,59,59;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;10,9,9,10;,
  4;9,5,5,9;,
  4;60,60,61,61;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;16,15,15,16;,
  4;15,11,11,15;,
  4;62,62,63,63;,
  4;18,19,19,18;,
  4;19,20,20,19;,
  4;22,21,21,22;,
  4;21,17,17,21;,
  4;64,64,65,65;,
  4;24,25,25,24;,
  4;25,26,26,25;,
  4;28,27,27,28;,
  4;27,23,23,27;,
  4;66,66,67,67;,
  4;30,31,31,30;,
  4;31,32,32,31;,
  4;34,33,33,34;,
  4;33,29,29,33;,
  4;68,68,69,69;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;70,39,39,70;,
  4;39,35,35,39;,
  4;71,71,72,72;,
  4;41,42,42,41;,
  4;42,43,43,42;,
  4;45,44,44,45;,
  4;44,40,40,44;,
  4;73,73,74,74;,
  4;47,48,48,47;,
  4;48,49,49,48;,
  4;51,50,50,51;,
  4;50,46,46,50;,
  4;75,75,76,76;,
  4;53,54,54,53;,
  4;54,55,55,54;,
  4;57,56,56,57;,
  4;56,52,52,56;,
  4;77,77,78,78;,
  3;79,79,79;,
  3;80,75,75;,
  3;81,81,81;,
  3;82,68,68;,
  3;83,71,71;,
  3;84,84,84;,
  3;85,77,77;,
  3;86,86,86;,
  3;87,60,60;,
  3;88,58,58;,
  3;89,89,89;,
  3;90,73,73;,
  3;91,91,91;,
  3;92,62,62;,
  3;93,93,93;,
  3;94,64,64;,
  3;95,95,95;,
  3;96,66,66;,
  3;97,2,2;,
  4;98,98,98,98;,
  4;99,99,99,99;,
  4;100,100,100,100;,
  4;122,122,122,122;,
  4;123,123,123,123;,
  4;101,101,101,101;,
  4;102,102,102,102;,
  4;103,103,103,103;,
  4;124,124,124,124;,
  4;123,123,123,123;,
  4;104,104,104,104;,
  4;105,105,105,105;,
  4;106,106,106,106;,
  4;125,125,125,125;,
  4;123,123,123,123;,
  4;107,107,107,107;,
  4;108,108,108,108;,
  4;109,109,109,109;,
  4;126,126,126,126;,
  4;123,123,123,123;,
  4;110,110,110,110;,
  4;111,111,111,111;,
  4;112,112,112,112;,
  4;127,127,127,127;,
  4;123,123,123,123;,
  4;113,113,113,113;,
  4;114,114,114,114;,
  4;115,115,115,115;,
  4;128,128,128,128;,
  4;123,123,123,123;,
  4;116,116,116,116;,
  4;117,117,117,117;,
  4;118,118,118,118;,
  4;129,129,129,129;,
  4;123,123,123,123;,
  4;119,119,119,119;,
  4;120,120,120,120;,
  4;121,121,121,121;,
  4;130,130,130,130;,
  4;123,123,123,123;;
 }
 MeshTextureCoords {
  329;
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}