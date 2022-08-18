<h1>Linear Algebra</h1>

<h2> 1. Vectors</h2>

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
![Screenshot from 2022-08-18 20-10-22](https://user-images.githubusercontent.com/103848930/185448746-1c78c6ff-c6b0-47a1-87b0-668f1343049f.png)<br>
 Transformations having linearly dependent vectors lead to limiting of the span to 1-D (a line).<br>
</p>

## 4. Matrix multiplication as composition

<p>
 Composition is applying two transformations in steps. Product of two transformation matrices gives the composition matrix. <br>
 ![Screenshot from 2022-08-18 21-12-25](https://user-images.githubusercontent.com/103848930/185450104-1e3bb87d-b1cf-49d8-aa2f-e26f67652993.png)<br>
 Order of multiplying matrices is not commutative, it leads to different landing points.<br>
 </p>
 
## 5. Determinant
<p>
 Determinant of a transformation matrix is the scaling factor for the area/volume of a space/region. Its -ve/+ve sign refers to the flipping of the space.<br>
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
 **Null space** or the **Kernel** is the space of all the vectors that become null. When the resultant vector is a null vector, the solution to the equation $A\vec{x}=\vec{v}$ is all the vectors in the null space.<br>
 
 
 
 
 
 
 