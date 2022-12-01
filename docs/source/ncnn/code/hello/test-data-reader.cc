#include "datareader.h"
#include "paramdict.h"
#include <iostream>

#ifndef MY_CHECK
#define MY_CHECK(x, y)                                                         \
  do {                                                                         \
    if (x != y) {                                                              \
      NCNN_LOGE(#x " != " #y);                                                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)
#endif

class ParamDict2 : public ncnn::ParamDict {
public:
  int load_param2(const ncnn::DataReader &dr) { return load_param(dr); }

  int load_param_bin2(const ncnn::DataReader &dr) { return load_param_bin(dr); }
};

void TestDataReader() {
  NCNN_LOGE("Test data reader\n");
  int32_t a = 4;
  FILE *fp = fopen("a.bin", "wb");
  fwrite(&a, sizeof(a), 1, fp);

  float f = 1.25;
  fwrite(&f, sizeof(f), 1, fp);

  fclose(fp);

  fp = fopen("a.bin", "rb");

  ncnn::DataReaderFromStdio dr(fp);
  int32_t p;
  float q;
  dr.read(&p, sizeof(p));
  dr.read(&q, sizeof(q));
  MY_CHECK(p, a);
  MY_CHECK(q, f);
  fclose(fp);

  // datareader with param dict
  fp = fopen("a.txt", "w");
  fprintf(fp, "0=100 1=1.250000 -23303=5,0.125,0.25,0.50,0.625,1.0");
  fclose(fp);

  fp = fopen("a.txt", "r");
  ncnn::DataReaderFromStdio dr2(fp);
  ParamDict2 pd;
  pd.load_param2(dr2);
  MY_CHECK(pd.get(0, 0), 100);
  MY_CHECK(pd.get(1, 0.f), 1.25);
  ncnn::Mat m = pd.get(3, ncnn::Mat());
  MY_CHECK(m.w, 5);
  MY_CHECK(m[0], 0.125);
  MY_CHECK(m[1], 0.25);
  MY_CHECK(m[2], 0.50);
  MY_CHECK(m[3], 0.625);
  MY_CHECK(m[4], 1.0);

  fclose(fp);

  // for binary
  //
  //     binary 0
  //     binary 100
  //     binary 1
  //     binary 1.250000
  //     binary 3 | array_bit
  //     binary 5
  //     binary 0.1
  //     binary 0.2
  //     binary 0.4
  //     binary 0.8
  //     binary 1.0
  //     binary -233(EOP)
  fp = fopen("a.bin", "wb");
  int32_t id = 0;
  fwrite(&id, sizeof(id), 1, fp);
  int32_t val = 100;
  fwrite(&val, sizeof(val), 1, fp);

  id = 1;
  float val2 = 1.25;
  fwrite(&id, sizeof(id), 1, fp);
  fwrite(&val, sizeof(val2), 1, fp);

  id = -23303;
  fwrite(&id, sizeof(id), 1, fp);
  int32_t len = m.w;
  fwrite(&len, sizeof(len), 1, fp);
  fwrite(m.data, sizeof(float), m.w, fp);

  int32_t eop = -233;
  fwrite(&eop, sizeof(eop), 1, fp);
  fclose(fp);

  fp = fopen("a.bin", "rb");

  ncnn::DataReaderFromStdio dr3(fp);
  ParamDict2 pd3;
  pd3.load_param_bin2(dr3);
  fclose(fp);
  MY_CHECK(pd.get(0, 0), 100);

  // ncnn does not know that param 1 is a float. The user has to specify that!
  MY_CHECK(pd.get(1, 0.f), 1.25);

  ncnn::Mat m2 = pd.get(3, ncnn::Mat());
  MY_CHECK(m2.w, 5);
  MY_CHECK(m2[0], 0.125);
  MY_CHECK(m2[1], 0.25);
  MY_CHECK(m2[2], 0.50);
  MY_CHECK(m2[3], 0.625);
  MY_CHECK(m2[4], 1.0);
}
