// class Matrix {
//     constructor(mat) {
//         this.mat = mat;
//     }
//
//     add(other) {
//         for (let i = 0; i < mat.length; i ++) {
//             for (let j = 0; j < mat[i].length; j ++) {
//                 this.mat[i][j] += other.mat[i][j];
//             }
//         }
//         return this;
//     }
//
//     mult() {
//         for (let i = 0; i < mat.length; i ++) {
//             for (let j = 0; j < mat[i].length; j ++) {
//                 this.mat[i][j] += other.mat[i][j];
//             }
//         }
//         return this;
//     }
// }

function MatrixAdd(a, b) {
    let c = [];
    for (let i = 0; i < mat.length; i ++) {
        c[i] = [];
        for (let j = 0; j < mat[i].length; j ++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
