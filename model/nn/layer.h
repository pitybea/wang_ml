//  CopyRight none@nothing.not
#ifndef MODEL_NN_LAYER_H_
#define MODEL_NN_LAYER_H_

#include <vector>

#include "../../types.h"

using std::vector;

template<class T>
struct layerPara {
  vector<T> b;
  vector<vector<T>> w;
  vector<vector<vector<T>>> v;
  layerPara(int input_d, int output_d, int rank, T val) :
    w(vector<vector<T>>(output_d, vector<T>(input_d, val))),
    b(vector<T>(output_d, val)) {
      if (rank > 0) {
        v = vector<vector<vector<T>>>(output_d, vector<vector<T>>
                                      (input_d, vector<T>(rank, val)));
      }
    }
};

class layer {
 public:
  layer(int, int, int);
  void linearFunc(vector<floatType>*, const vector<floatType>&);
  virtual void forward(vector<floatType>*, const vector<floatType>&);
  virtual void backward(vector<floatType>*, const vector<floatType>&,
                const vector<floatType>&, const vector<floatType>&);
  
 private:
  int input_dim;
  int output_dim;
  layerPara<floatType> parameters;
  
};

class layerFM : public layer {
 public:
  layerFM(int, int, int);
  void initV(floatType);
  
 private:
  int class_num;
  int rank;
};

#endif  // MODEL_NN_LAYER_H_
