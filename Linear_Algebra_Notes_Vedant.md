<h1>Linear Algebra</h1>

## Table of Contents
<p>
1. [Vectors](#vectors)
 
</p>

## 1. Vectors <a name="vectors"></a>

<p> Defined as ordered list of numbers or,<br>
 Quantity having both magnitude and direction 
 [13,4]=[x,y]
</p>

<p> Scaling of vectors: Multiplying a constant(scalar) with a vector <br>
    2[1,2] = [2,4]
</p>

<h2> 2. Linear Combinations, Span and Basis Vectors </h2>

<p> $\vec{v}$= i + 2j = [1,2], where i and j are unit basis vectors<br>
    Linear combination: $a\vec{v}+ b\vec{w}$<br>
    It basically represents the span of the vectors, when taken as basis vectors<br>
    For 2 vectors: It is a plane    For 3 vectors: It can represent all vectors<br>
    Linearly dependent: $\vec{u} = a\vec{v}+ b\vec{w}$ <br>
    Linearly independent: $\vec{u} \neq a\vec{v}+ b\vec{w}$<br>
    Basis of vector space is a set of Linearly independent vectors that span the full space
</p>

## 3. Linear Transformations

<p> Transformations are basically functions that change the landing direction of the input vector<br>
 Linear transformations are those in which the lines remain lines and the origin remains fixed. The axes gridlines remain parallel and evenly spaced.<br>
 We only have to consider where the basis vectors $\hat{i}$ and $\hat{j}$ land after the transformation<br>
 <figure><img src="./assets/Screenshot from 2022-08-18 20-10-22.png"><figcaption>image caption</figcaption></figure>
 Transformations having linearly dependent vectors lead to limiting of the span to 1-D (a line).<br>
 Linearity have following characteristics :<br>
 1. Additivity: $L(\vec{v} + \vec{w}) = L(\vec{v}) + L(\vec{w})$ <br>
 2. Scalability: $L(c \vec{v}) = cL(\vec{v})$
 
</p>

## 4. Matrix multiplication as composition

<p>
 Composition is applying two transformations in steps. Product of two transformation matrices gives the composition matrix. <br>
 <img src="/assets/Screenshot from 2022-08-18 21-12-25.png"><br>
 Order of multiplying matrices is not commutative, it leads to different landing points.<br>
 </p>
 
## 5. Determinant
<p>
 Determinant of a transformation matrix is the scaling factor for the area/volume of a space/region. Its -ve/+ve sign refers to the flipping of the space.<br>
 <img src="/assets/image.png"><br>
 Flipping refers to whether or not the basis vectors $\hat{i}$ and $\hat{j}$ change their relative orientation. In 3-D, it means that the relative 
 positions of the axes change in orientation. First, they can be represented by right-hand rule, and then by left-hand. <br>
 When determinant is zero, it implies the area scales down to nothing.
 
 </p>
 
 ## 6. Inverse of a Matrix
 
 <p>
 Inverse transformation matrix is the process of nullifying the said matrix to get the original vector back.<br>
 $A\vec{x}=\vec{v} \implies \vec{x}= A^{-1}\vec{v}$<br>
 Basically, $A^{-1}A=I$(identity matrix)<br>
 </p>
 
 ## 7. Rank
 
 <p>
 Rank is the number of dimensions in the output of the transformation. <br>
 When it is 1, output is a line, when it is 2, output is a plane.<br>
 Set of all possible outputs of a transformation is called the column space $\equiv$ span of basis vectors. Rank is the number of dimesnions in the column space. When all the possible dimensions are in the output, the matrix is called full rank. <br>
 <strong>Null space</strong> or the <strong>Kernel</strong> is the space of all the vectors that become null. When the resultant vector is a null vector, the solution to the equation $A\vec{x}=\vec{v}$ is all the vectors in the null space.<br>
 </p>
 
 ## 8. Non square matrices
 <p>
 For matrix of order $m \times n$, n indicates the number of dimesnions of the input vector, and m indicates the dimesnions of the output vector.<br>
 <img src="assets/nonsquare.jpeg">
 </p>
 
 ## 9. Dot Products and Duality
 <p>
 Dot product of two vectors is the product of length of one vector with length of projection on the first vector. It is also given by the multiplication of the respective elements, for vectors of same dimension. <br>
 
 $$\begin{bmatrix}
    1 \\
    2 \\
    3
   \end{bmatrix} \bullet 
   \begin{bmatrix*}[r]
    4 \\
    5 \\
    6 \\
    \end{bmatrix*}=1 \times 4 + 2 \times 5 + 3 \times 6 = 32$$ 
 
 or 
 <img src="assets/Screenshot from 2022-08-19 12-36-18.png"><br>
 Both these definitions are explained by duality
 
<img src="assets/Screenshot from 2022-08-19 12-51-21.png">
So dot product is basically a transformation that squishes a vector onto a number line, and is associated with another matrix/vector. 
 </p>
 
 ## 10. Cross products
 <p>
 It is the vector, whose magnitude is the area of the parallelogram enclosed by the two vectors, and its direction perpendicular to the plane of the parallelogram, determined using the right hand rule. 
 $$\vec{p} = \vec{a} \times \vec{b}$$
 The area of the parallelogram is measured by taking the determinant of the two vectors.<br>
 <img src="assets/Screenshot from 2022-08-19 13-07-59.png">
 
 ![Screenshot from 2022-08-19 15-42-22](https://user-images.githubusercontent.com/103848930/185597174-6c3518f9-8b74-460d-ac86-29fd3acc1f63.png)
 </p>
 
 ## 11. Change of basis
 
<p>
 $$A \begin{bmatrix}
      x^{'} \\
      y^{'} 
      \end{bmatrix} = \begin{bmatrix*}[r]
                      x \\
                      y 
                      \end{bmatrix*}$$
 
 where $x^{'}$ & $y^{'}$ represent the coordinates of the vector in the system where the basis vectors are changed.<br>
 So changing of basis is basically applying another transformation.
 </p>
 
 ## 12. Eigenvectors and Eigenvalues
 <p>
 Eigenvectors are the vectors whose span doesn't change after a linear transformation is applied to them. They still exist on the axis of the direction of original vector (span). The magnitude by which they are stretched or contracted is called their eigenvalue.<br>
 If any one vector is an eigenvector for a particular transformation, then all the vectors along the span of this vector are also eigenvectors.<br>
 Negative eigenvalues imply that the vectors get flipped and scaled by the value.<br>
 $$A \vec{v} = \lambda \vec{v} $$
 where $\vec{v}$ is the eigenvector, and $\lambda$ is the eigenvalue for the transfromation matrix A.<br>
 $$A \vec{v} - \lambda I \vec{v} = 0$$
 $$(A-\lambda I)\vec{v}=0$$
 Therefore, the det $(A-\lambda I)$ = 0 gives the eigenvalue of the corresponding eigenvector. <br>
 It is possible for transformations to have no eigenvectors, e.g., imaginary eigenvalues obtained in rotation of vectors.<br>
 It is also possible that all vectors are eigenvectors, like in case of scaling.<br>
 A diagonal matrix refers to the case where the basis vectors are eigenvectors. When eigenvectors are made to be basis vectors, the transformation matrix becomes a diagonal one, hence making easier to interpret what will happen to a vector when it is transformed multiple times by the same matrix.<br> 
 $$E^{-1} A E = T$$
 where E is the eigenbasis matrix, A is the original transformation, and T is the diagonal matrix, which transforms the system where the eigenvectors are the basis vectors. Of course, the transformation should have enough eigenvectors to be able to change into basis vectors.
 </p>
 
 ## 13. Abstract Vector Spaces
 <p>
 Any form of data can be represented by vectors, as long as it has some sense of linearity in it. All the concepts of linear algebra can therefore be applied extended to these spaces as well. The following axioms can be applied when we represent something as a vector space.<br>
<img src="assets/Screenshot from 2022-08-19 23-20-05.png">
 </p>
 
 

 
 
