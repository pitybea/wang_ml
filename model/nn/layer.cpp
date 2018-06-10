//  CopyRight none@nothin.not

#include "./layer.h"

layer::layer(int input_d, int output_d, int rank = 0) :
    input_dim(input_d), output_dim(output_d),
    parameters(layerPara<floatType>(input_d, output_d, rank, 0.0f)) {
}

void layer::linearFunc(vector<floatType>* result,
                       const vector<floatType>& input) {
  for (int i = 0; i < output_dim; i++) {
    (*result)[i] = parameters.b[i];
    for (int j = 0; j < input_dim; j++) {
      (*result)[i] += parameters.w[i][j] * input[j];
    }
  }
}

layerFM::layerFM(int input_d, int class_num_, int rank_) :
    layer(input_d, class_num_ - 1, rank_), class_num(class_num_),
    rank(rank_) {
}
