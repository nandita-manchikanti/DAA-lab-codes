#include<iostream>
#include <bits/stdc++.h>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;

//Input:   Integer Array A and an integer p
//Question: Does there exist q and r in A such that p=q+r

//Two pointer method-->More effecient
int sum1(int array[],int n,int p)
{
    sort(array,array+n);

    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (array[low] + array[high] == p)
        {
          cout << "The pair is : (" <<array[low] << ", " <<array[high] << ")"<<endl;
        }
        if (array[low] + array[high] > p)
        {
          high--;
        }
        else
        {
          low++;
        }
    }
    return 0;
}

//Two for loops
int sum2(int array[],int n,int p)
{
    cout<<"The pairs are : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i]+array[j]==p)
            {
                cout<<"("<<array[i]<<","<<array[j]<<")"<<endl;
            }
        }
    }
    return 0;
}

//Using map -->store the frequencies of each number
int sum3(int arr[],int n,int sum)
{
    // Store counts of all elements in map m O(n)
    unordered_map<int, int> m;

    // Traverse through all elements
    for (int i = 0; i < n; i++)
    {
        // Search if a pair can be formed with arr[i].
        int rem = sum - arr[i];
        if (m.find(rem) != m.end())
        {
            int count = m[rem];
            for (int j = 0; j < count; j++)
                cout << "(" << rem << ","<< arr[i] << ")"<< endl;
        }
        m[arr[i]]++;
    }
    return 0;
}
int main()
{
    ofstream myfile;
    myfile.open("Ques1Graph.csv",std::ios::trunc);

    clock_t a,b,c;
    int n=100;
    int p;
    /*cout<<"How many numbers do you want to enter :";
    cin>>n;
    cout<<"Enter the elements of the array :\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }*/
    int array1[100]={26,32,40,62,19,40,74,8,84,20,59,16,16,70,29,90,89,53,6,41,72,67,39,26,67,49,31,19,13,41,18,8,26,14,22,91,62,31,39,74,36,0,95,14,12,60,39,87,33,27,7,35,89,58,87,13,56,64,32,30,43,0,96,87,6,8,50,37,71,32,60,17,44,42,73,40,36,39,41,60,88,94,7,3,73,82,32,48,91,62,95,67,36,67,68,78,65,87,21,76};
    int array2[100]={1,56,132,59,115,197,116,137,106,57,155,42,133,40,150,140,61,5,6,90,120,22,129,76,153,43,167,83,144,109,199,170,6,45,149,64,99,38,5,6,61,110,65,186,2,145,113,154,196,140,30,82,151,83,160,12,104,197,93,42,98,66,104,109,138,45,72,48,93,171,64,183,154,77,11,142,82,178,185,128,0,33,144,54,54,61,123,72,69,13,23,18,71,86,55,32,193,39,187,95};
    int array3[100]={40,233,148,207,73,234,257,265,21,58,53,198,117,253,24,22,0,30,181,178,241,146,48,78,234,196,228,103,121,45,225,76,80,51,37,287,227,58,90,117,258,140,211,212,252,10,91,137,76,52,26,214,195,196,57,23,69,70,244,85,255,224,198,131,219,111,183,282,71,204,193,191,130,119,276,242,210,212,93,168,222,88,270,164,22,189,292,100,220,91,3,57,5,198,247,260,23,153,161,206};
    int array4[100]={23,124,25,28,280,385,226,178,374,135,332,27,377,156,292,335,83,190,36,161,346,41,138,369,372,170,74,341,373,255,280,92,386,98,80,14,357,44,373,236,118,232,260,73,177,270,187,387,103,230,49,395,141,369,317,113,108,149,323,94,397,3,393,16,194,249,292,70,333,174,42,243,170,282,390,5,32,35,354,314,209,256,202,310,280,181,42,290,232,52,2,120,260,374,368,67,160,357,9,161};
    int array5[100]={461,226,101,27,456,216,374,347,329,78,37,10,407,73,28,100,198,457,435,305,133,261,357,474,162,153,44,428,215,130,185,176,2,149,363,210,446,335,432,222,57,485,128,391,113,94,409,291,25,471,257,449,7,1,30,172,368,492,74,434,243,255,121,274,309,36,409,365,333,204,476,430,61,372,185,147,46,357,396,203,117,255,145,265,135,432,211,101,259,416,188,341,404,133,4,171,483,281,398,39};
    int array6[100]={496,512,308,136,422,599,185,568,466,365,45,61,233,376,97,17,486,326,454,107,491,473,57,168,412,28,287,180,337,444,560,97,329,452,363,14,223,553,243,482,61,33,73,467,174,580,3,245,237,113,191,577,462,279,253,194,568,162,454,63,171,237,560,493,120,199,538,127,171,321,121,562,76,301,470,10,491,52,423,365,61,346,323,137,327,506,21,290,443,21,136,498,596,375,307,585,475,294,272,260};
    int array7[100]={338,386,695,645,475,275,130,108,648,534,125,122,568,225,681,528,588,664,632,575,373,310,689,659,380,4,303,548,244,53,521,64,208,552,135,464,692,459,179,372,98,401,254,365,486,603,370,553,394,490,365,599,614,594,433,517,389,454,523,471,163,172,294,63,41,5,23,691,129,94,38,76,137,446,54,566,455,83,583,341,317,171,140,461,312,590,170,527,654,684,353,321,412,438,654,166,323,690,111,538};
    int array8[100]={338,386,695,645,475,275,130,108,648,534,125,122,568,225,681,528,588,664,632,575,373,310,689,659,380,4,303,548,244,53,521,64,208,552,135,464,692,459,179,372,98,401,254,365,486,603,370,553,394,490,365,599,614,594,433,517,389,454,523,471,163,172,294,63,41,5,23,691,129,94,38,76,137,446,54,566,455,83,583,341,317,171,140,461,312,590,170,527,654,684,353,321,412,438,654,166,323,690,111,538};
    int array9[100]={688,790,451,322,663,387,838,604,353,498,770,270,751,668,643,205,410,324,151,400,287,124,681,606,14,630,624,618,433,583,896,96,847,2,876,788,794,246,342,97,202,844,178,170,225,355,145,368,248,689,510,446,637,384,665,305,705,445,410,356,541,665,377,800,314,316,133,656,360,410,442,866,529,524,305,616,802,526,335,465,27,143,169,9,424,95,762,31,573,145,602,670,847,663,461,372,318,667,458,581};
    int array10[100]={413,855,130,920,431,601,58,333,922,100,466,290,216,57,538,713,630,854,364,262,748,873,730,281,819,405,155,842,658,830,924,505,56,209,965,916,964,915,680,824,763,128,524,358,745,633,559,697,349,836,935,386,571,142,744,122,194,103,430,888,925,724,23,232,416,335,644,413,261,141,758,101,281,547,781,600,809,229,679,828,694,691,571,418,824,814,564,286,58,909,67,440,826,440,359,550,962,623,927,803};
    int array11[100]={821,832,376,1057,826,1031,746,382,807,57,904,985,778,752,648,953,48,266,533,61,28,833,764,852,780,438,342,802,266,264,965,106,130,819,264,508,1049,396,649,629,787,513,919,972,1088,329,544,389,2,370,587,86,658,172,1018,291,429,645,624,629,454,744,720,719,589,562,331,178,1008,773,156,472,768,109,879,471,345,353,587,705,989,689,696,21,1033,927,149,475,552,503,369,474,85,513,363,922,700,744,319,866};
    int array12[100]={911,378,240,39,763,162,1188,892,466,769,246,229,99,390,749,290,132,333,901,756,99,380,490,65,391,998,397,311,371,1186,644,682,877,558,908,1107,945,659,1177,964,744,40,995,1159,875,391,557,651,40,631,128,94,643,79,670,883,1077,800,521,790,733,125,1114,487,907,195,1103,358,14,126,951,986,823,91,645,671,205,957,1050,319,816,320,156,853,309,149,154,1041,660,399,1137,1166,52,763,1034,522,466,800,875,345};
    int array13[100]={168,205,614,604,864,901,161,667,1136,119,1012,626,747,1055,169,124,962,616,1072,962,567,861,575,722,1057,1081,576,282,1122,1070,1111,385,495,1128,753,1002,483,961,45,1005,964,1101,448,140,255,1204,568,1244,1138,862,1214,613,729,734,253,1002,302,402,653,94,911,1166,1152,910,790,560,558,865,289,813,355,860,742,977,286,33,546,605,619,148,857,1257,475,1260,836,214,654,280,423,330,515,298,415,1256,921,6,539,360,1019,135};
    int array14[100]={79,547,156,170,1078,1322,1281,1261,1397,715,408,997,17,708,1094,718,880,1234,473,37,442,107,1363,985,374,354,924,782,476,391,36,753,1031,972,346,1000,798,525,443,331,450,146,1399,1399,465,439,458,477,225,1380,176,1279,1382,950,275,47,390,1095,302,8,889,918,535,238,1202,790,448,1206,1166,763,364,142,1389,1384,1099,751,212,505,217,954,792,804,271,669,1319,333,34,681,427,301,203,39,1301,1151,1257,1343,93,811,272,1215};
    int array15[100]={335,1062,770,175,719,212,874,851,835,144,483,71,658,1422,1348,1191,755,1050,407,422,974,435,10,426,1377,223,959,447,744,300,1089,98,1274,884,440,218,1214,1116,1251,125,644,436,1030,1283,1046,1309,682,993,545,1048,594,963,694,1391,1279,647,531,1154,1003,573,1018,1284,656,452,817,366,1369,1288,141,191,935,1188,395,868,1259,173,1217,267,950,845,169,707,126,171,1359,481,1232,163,1169,1249,925,465,41,519,1408,1430,1370,1131,939,1066};
    int array16[100]={1036,506,1473,1294,767,910,972,289,812,466,284,947,1263,845,1012,209,1598,319,49,910,688,768,1036,385,952,1593,1324,1001,1468,817,1558,484,1466,390,468,426,1000,1164,106,87,263,132,1210,1126,575,408,336,1476,1225,592,658,1047,1206,921,962,465,970,1262,1385,1291,888,45,808,859,1231,339,482,281,1415,508,345,924,171,40,96,1470,672,46,1004,1305,662,1030,1367,649,1270,352,1509,874,984,167,834,69,1373,721,34,86,999,91,1479,1033};
    int array17[100]={764,890,955,1225,1176,1682,489,511,1649,1469,341,1170,1215,484,308,575,794,1205,828,1619,498,1117,618,1249,1231,702,590,891,1452,1476,529,621,1111,1166,1624,870,421,1525,1555,1338,625,1546,690,1504,1038,875,1397,214,844,1661,1533,803,109,713,1361,1131,11,1502,657,1480,1484,8,705,579,852,1551,515,99,385,181,1159,1440,659,155,833,743,562,383,957,778,1513,562,1408,550,457,986,228,1183,1298,1074,82,1431,1421,552,891,1037,476,255,689,1596};
    int array18[100]={997,1064,246,461,237,1537,752,910,420,1767,36,1062,724,11,342,949,1518,1624,14,411,136,1063,280,824,873,818,373,1070,250,753,621,1677,132,1470,597,1431,738,562,1229,1668,219,759,78,184,354,1201,464,8,1637,1513,366,1526,1466,402,1692,509,103,1094,779,774,359,53,1125,1077,179,38,982,939,1798,1144,1439,1122,725,1238,1604,220,636,988,975,700,779,10,39,528,973,1007,1757,920,1636,983,617,854,660,1713,850,1353,1200,285,1756,1793};
    int array19[100]={1425,1310,804,504,154,969,743,1038,1010,970,528,484,1615,1122,532,637,686,381,1517,1774,1871,406,50,1341,271,632,392,345,1183,584,868,1393,1253,800,1483,417,510,1665,701,58,939,132,1364,613,459,1316,1515,1605,1260,413,302,179,1316,174,1789,231,863,1013,648,1405,196,1774,1100,319,448,1671,1656,144,1244,1209,949,1718,1209,842,1439,107,1072,860,1772,1860,1113,346,1812,289,403,1850,223,1816,1145,1856,943,517,1027,1037,1317,682,112,672,271,891};
    int array20[100]={837,31,990,1275,835,354,864,1916,922,1000,525,1195,1980,1053,951,165,1925,1470,673,1236,712,1038,151,1718,1789,341,1994,426,430,1068,1718,1014,560,1944,522,427,1665,936,1469,874,1281,1415,1039,241,1456,22,412,70,975,1088,1727,418,786,96,1585,133,1598,1428,383,1647,1658,842,565,597,699,1059,1205,210,286,1132,1859,1669,861,1101,1177,1143,388,150,313,992,1267,1966,1634,1543,246,703,479,252,1897,1787,1120,1331,1608,1315,524,1483,612,574,1594,1299};

    cout<<"Enter an integer :\n";
    cin>>p;

    a=clock();
    sum1(array1,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array2,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array3,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array4,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array5,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array6,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array7,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array8,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array9,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array10,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array11,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array12,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array13,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array14,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array15,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array16,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array17,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array18,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array19,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    a=clock();
    sum1(array20,n,p);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array1,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array2,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array3,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array4,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array5,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array6,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array7,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array8,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array9,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    b=clock();
    sum2(array10,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array11,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array12,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array13,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array14,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array15,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array16,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array17,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array18,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

        b=clock();
    sum2(array19,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;


    b=clock();
    sum2(array20,n,p);
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;

    c=clock();
    sum3(array1,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array2,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array3,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array4,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array5,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array6,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array7,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array8,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array9,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array10,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array11,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array12,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array13,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array14,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array15,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array16,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

        c=clock();
    sum3(array17,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

            c=clock();
    sum3(array18,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

            c=clock();
    sum3(array19,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

            c=clock();
    sum3(array20,n,p);
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;

    return 0;
}

