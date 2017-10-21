//***************************************************************************************
// GeometryGenerator.cpp by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************

#include "GeometryGenerator.h"
#include <algorithm>

using namespace DirectX;

GeometryGenerator::MeshData GeometryGenerator::CreateBox(float width, float height, float depth, uint32 numSubdivisions)
{
    MeshData meshData;

    //
	// Create the vertices.
	//

	Vertex v[24];

	float w2 = 0.5f*width;
	float h2 = 0.5f*height;
	float d2 = 0.5f*depth;
    
	// Fill in the front face vertex data.
	v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the back face vertex data.
	v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the top face vertex data.
	v[8]  = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[9]  = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	// Fill in the bottom face vertex data.
	v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Fill in the left face vertex data.
	v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	// Fill in the right face vertex data.
	v[20] = Vertex(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[21] = Vertex(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[22] = Vertex(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	v[23] = Vertex(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	meshData.Vertices.assign(&v[0], &v[24]);
 
	//
	// Create the indices.
	//

	uint32 i[36];

	// Fill in the front face index data
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	// Fill in the back face index data
	i[6] = 4; i[7]  = 5; i[8]  = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	// Fill in the top face index data
	i[12] = 8; i[13] =  9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	// Fill in the bottom face index data
	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	// Fill in the left face index data
	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	// Fill in the right face index data
	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;

	meshData.Indices32.assign(&i[0], &i[36]);

    // Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

    for(uint32 i = 0; i < numSubdivisions; ++i)
        Subdivide(meshData);

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateSphere(float radius, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

	//
	// Compute the vertices stating at the top pole and moving down the stacks.
	//

	// Poles: note that there will be texture coordinate distortion as there is
	// not a unique point on the texture map to assign to the pole when mapping
	// a rectangular texture onto a sphere.
	Vertex topVertex(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Vertex bottomVertex(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData.Vertices.push_back( topVertex );

	float phiStep   = XM_PI/stackCount;
	float thetaStep = 2.0f*XM_PI/sliceCount;

	// Compute vertices for each stack ring (do not count the poles as rings).
	for(uint32 i = 1; i <= stackCount-1; ++i)
	{
		float phi = i*phiStep;

		// Vertices of ring.
        for(uint32 j = 0; j <= sliceCount; ++j)
		{
			float theta = j*thetaStep;

			Vertex v;

			// spherical to cartesian
			v.Position.x = radius*sinf(phi)*cosf(theta);
			v.Position.y = radius*cosf(phi);
			v.Position.z = radius*sinf(phi)*sinf(theta);

			// Partial derivative of P with respect to theta
			v.TangentU.x = -radius*sinf(phi)*sinf(theta);
			v.TangentU.y = 0.0f;
			v.TangentU.z = +radius*sinf(phi)*cosf(theta);

			XMVECTOR T = XMLoadFloat3(&v.TangentU);
			XMStoreFloat3(&v.TangentU, XMVector3Normalize(T));

			XMVECTOR p = XMLoadFloat3(&v.Position);
			XMStoreFloat3(&v.Normal, XMVector3Normalize(p));

			v.TexC.x = theta / XM_2PI;
			v.TexC.y = phi / XM_PI;

			meshData.Vertices.push_back( v );
		}
	}

	meshData.Vertices.push_back( bottomVertex );

	//
	// Compute indices for top stack.  The top stack was written first to the vertex buffer
	// and connects the top pole to the first ring.
	//

    for(uint32 i = 1; i <= sliceCount; ++i)
	{
		meshData.Indices32.push_back(0);
		meshData.Indices32.push_back(i+1);
		meshData.Indices32.push_back(i);
	}
	
	//
	// Compute indices for inner stacks (not connected to poles).
	//

	// Offset the indices to the index of the first vertex in the first ring.
	// This is just skipping the top pole vertex.
    uint32 baseIndex = 1;
    uint32 ringVertexCount = sliceCount + 1;
	for(uint32 i = 0; i < stackCount-2; ++i)
	{
		for(uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j);
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j+1);
			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);

			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j);
			meshData.Indices32.push_back(baseIndex + i*ringVertexCount + j+1);
			meshData.Indices32.push_back(baseIndex + (i+1)*ringVertexCount + j+1);
		}
	}

	//
	// Compute indices for bottom stack.  The bottom stack was written last to the vertex buffer
	// and connects the bottom pole to the bottom ring.
	//

	// South pole vertex was added last.
	uint32 southPoleIndex = (uint32)meshData.Vertices.size()-1;

	// Offset the indices to the index of the first vertex in the last ring.
	baseIndex = southPoleIndex - ringVertexCount;
	
	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(southPoleIndex);
		meshData.Indices32.push_back(baseIndex+i);
		meshData.Indices32.push_back(baseIndex+i+1);
	}

    return meshData;
}
 
void GeometryGenerator::Subdivide(MeshData& meshData)
{
	// Save a copy of the input geometry.
	MeshData inputCopy = meshData;


	meshData.Vertices.resize(0);
	meshData.Indices32.resize(0);

	//       v1
	//       *
	//      / \
	//     /   \
	//  m0*-----*m1
	//   / \   / \
	//  /   \ /   \
	// *-----*-----*
	// v0    m2     v2

	uint32 numTris = (uint32)inputCopy.Indices32.size()/3;
	for(uint32 i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy.Vertices[ inputCopy.Indices32[i*3+0] ];
		Vertex v1 = inputCopy.Vertices[ inputCopy.Indices32[i*3+1] ];
		Vertex v2 = inputCopy.Vertices[ inputCopy.Indices32[i*3+2] ];

		//
		// Generate the midpoints.
		//

        Vertex m0 = MidPoint(v0, v1);
        Vertex m1 = MidPoint(v1, v2);
        Vertex m2 = MidPoint(v0, v2);

		//
		// Add new geometry.
		//

		meshData.Vertices.push_back(v0); // 0
		meshData.Vertices.push_back(v1); // 1
		meshData.Vertices.push_back(v2); // 2
		meshData.Vertices.push_back(m0); // 3
		meshData.Vertices.push_back(m1); // 4
		meshData.Vertices.push_back(m2); // 5
 
		meshData.Indices32.push_back(i*6+0);
		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+5);

		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+4);
		meshData.Indices32.push_back(i*6+5);

		meshData.Indices32.push_back(i*6+5);
		meshData.Indices32.push_back(i*6+4);
		meshData.Indices32.push_back(i*6+2);

		meshData.Indices32.push_back(i*6+3);
		meshData.Indices32.push_back(i*6+1);
		meshData.Indices32.push_back(i*6+4);
	}
}

GeometryGenerator::Vertex GeometryGenerator::MidPoint(const Vertex& v0, const Vertex& v1)
{
    XMVECTOR p0 = XMLoadFloat3(&v0.Position);
    XMVECTOR p1 = XMLoadFloat3(&v1.Position);

    XMVECTOR n0 = XMLoadFloat3(&v0.Normal);
    XMVECTOR n1 = XMLoadFloat3(&v1.Normal);

    XMVECTOR tan0 = XMLoadFloat3(&v0.TangentU);
    XMVECTOR tan1 = XMLoadFloat3(&v1.TangentU);

    XMVECTOR tex0 = XMLoadFloat2(&v0.TexC);
    XMVECTOR tex1 = XMLoadFloat2(&v1.TexC);

    // Compute the midpoints of all the attributes.  Vectors need to be normalized
    // since linear interpolating can make them not unit length.  
    XMVECTOR pos = 0.5f*(p0 + p1);
    XMVECTOR normal = XMVector3Normalize(0.5f*(n0 + n1));
    XMVECTOR tangent = XMVector3Normalize(0.5f*(tan0+tan1));
    XMVECTOR tex = 0.5f*(tex0 + tex1);

    Vertex v;
    XMStoreFloat3(&v.Position, pos);
    XMStoreFloat3(&v.Normal, normal);
    XMStoreFloat3(&v.TangentU, tangent);
    XMStoreFloat2(&v.TexC, tex);

    return v;
}

GeometryGenerator::MeshData GeometryGenerator::CreateGeosphere(float radius, uint32 numSubdivisions)
{
    MeshData meshData;

	// Put a cap on the number of subdivisions.
    numSubdivisions = std::min<uint32>(numSubdivisions, 6u);

	// Approximate a sphere by tessellating an icosahedron.

	const float X = 0.525731f; 
	const float Z = 0.850651f;

	XMFLOAT3 pos[12] = 
	{
		XMFLOAT3(-X, 0.0f, Z),  XMFLOAT3(X, 0.0f, Z),  
		XMFLOAT3(-X, 0.0f, -Z), XMFLOAT3(X, 0.0f, -Z),    
		XMFLOAT3(0.0f, Z, X),   XMFLOAT3(0.0f, Z, -X), 
		XMFLOAT3(0.0f, -Z, X),  XMFLOAT3(0.0f, -Z, -X),    
		XMFLOAT3(Z, X, 0.0f),   XMFLOAT3(-Z, X, 0.0f), 
		XMFLOAT3(Z, -X, 0.0f),  XMFLOAT3(-Z, -X, 0.0f)
	};

    uint32 k[60] =
	{
		1,4,0,  4,9,0,  4,5,9,  8,5,4,  1,8,4,    
		1,10,8, 10,3,8, 8,3,5,  3,2,5,  3,7,2,    
		3,10,7, 10,6,7, 6,11,7, 6,0,11, 6,1,0, 
		10,1,6, 11,0,9, 2,11,9, 5,2,9,  11,2,7 
	};

    meshData.Vertices.resize(12);
    meshData.Indices32.assign(&k[0], &k[60]);

	for(uint32 i = 0; i < 12; ++i)
		meshData.Vertices[i].Position = pos[i];

	for(uint32 i = 0; i < numSubdivisions; ++i)
		Subdivide(meshData);

	// Project vertices onto sphere and scale.
	for(uint32 i = 0; i < meshData.Vertices.size(); ++i)
	{
		// Project onto unit sphere.
		XMVECTOR n = XMVector3Normalize(XMLoadFloat3(&meshData.Vertices[i].Position));

		// Project onto sphere.
		XMVECTOR p = radius*n;

		XMStoreFloat3(&meshData.Vertices[i].Position, p);
		XMStoreFloat3(&meshData.Vertices[i].Normal, n);

		// Derive texture coordinates from spherical coordinates.
        float theta = atan2f(meshData.Vertices[i].Position.z, meshData.Vertices[i].Position.x);

        // Put in [0, 2pi].
        if(theta < 0.0f)
            theta += XM_2PI;

		float phi = acosf(meshData.Vertices[i].Position.y / radius);

		meshData.Vertices[i].TexC.x = theta/XM_2PI;
		meshData.Vertices[i].TexC.y = phi/XM_PI;

		// Partial derivative of P with respect to theta
		meshData.Vertices[i].TangentU.x = -radius*sinf(phi)*sinf(theta);
		meshData.Vertices[i].TangentU.y = 0.0f;
		meshData.Vertices[i].TangentU.z = +radius*sinf(phi)*cosf(theta);

		XMVECTOR T = XMLoadFloat3(&meshData.Vertices[i].TangentU);
		XMStoreFloat3(&meshData.Vertices[i].TangentU, XMVector3Normalize(T));
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
    MeshData meshData;

	//
	// Build Stacks.
	// 

	float stackHeight = height / stackCount;

	// Amount to increment radius as we move up each stack level from bottom to top.
	float radiusStep = (topRadius - bottomRadius) / stackCount;

	uint32 ringCount = stackCount+1;

	// Compute vertices for each stack ring starting at the bottom and moving up.
	for(uint32 i = 0; i < ringCount; ++i)
	{
		float y = -0.5f*height + i*stackHeight;
		float r = bottomRadius + i*radiusStep;

		// vertices of ring
		float dTheta = 2.0f*XM_PI/sliceCount;
		for(uint32 j = 0; j <= sliceCount; ++j)
		{
			Vertex vertex;

			float c = cosf(j*dTheta);
			float s = sinf(j*dTheta);

			vertex.Position = XMFLOAT3(r*c, y, r*s);

			vertex.TexC.x = (float)j/sliceCount;
			vertex.TexC.y = 1.0f - (float)i/stackCount;

			// Cylinder can be parameterized as follows, where we introduce v
			// parameter that goes in the same direction as the v tex-coord
			// so that the bitangent goes in the same direction as the v tex-coord.
			//   Let r0 be the bottom radius and let r1 be the top radius.
			//   y(v) = h - hv for v in [0,1].
			//   r(v) = r1 + (r0-r1)v
			//
			//   x(t, v) = r(v)*cos(t)
			//   y(t, v) = h - hv
			//   z(t, v) = r(v)*sin(t)
			// 
			//  dx/dt = -r(v)*sin(t)
			//  dy/dt = 0
			//  dz/dt = +r(v)*cos(t)
			//
			//  dx/dv = (r0-r1)*cos(t)
			//  dy/dv = -h
			//  dz/dv = (r0-r1)*sin(t)

			// This is unit length.
			vertex.TangentU = XMFLOAT3(-s, 0.0f, c);

			float dr = bottomRadius-topRadius;
			XMFLOAT3 bitangent(dr*c, -height, dr*s);

			XMVECTOR T = XMLoadFloat3(&vertex.TangentU);
			XMVECTOR B = XMLoadFloat3(&bitangent);
			XMVECTOR N = XMVector3Normalize(XMVector3Cross(T, B));
			XMStoreFloat3(&vertex.Normal, N);

			meshData.Vertices.push_back(vertex);
		}
	}

	// Add one because we duplicate the first and last vertex per ring
	// since the texture coordinates are different.
	uint32 ringVertexCount = sliceCount+1;

	// Compute indices for each stack.
	for(uint32 i = 0; i < stackCount; ++i)
	{
		for(uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.Indices32.push_back(i*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j+1);

			meshData.Indices32.push_back(i*ringVertexCount + j);
			meshData.Indices32.push_back((i+1)*ringVertexCount + j+1);
			meshData.Indices32.push_back(i*ringVertexCount + j+1);
		}
	}

	BuildCylinderTopCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);
	BuildCylinderBottomCap(bottomRadius, topRadius, height, sliceCount, stackCount, meshData);

    return meshData;
}

void GeometryGenerator::BuildCylinderTopCap(float bottomRadius, float topRadius, float height,
											uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
	uint32 baseIndex = (uint32)meshData.Vertices.size();

	float y = 0.5f*height;
	float dTheta = 2.0f*XM_PI/sliceCount;

	// Duplicate cap ring vertices because the texture coordinates and normals differ.
	for(uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = topRadius*cosf(i*dTheta);
		float z = topRadius*sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData.Vertices.push_back( Vertex(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData.Vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Index of center vertex.
	uint32 centerIndex = (uint32)meshData.Vertices.size()-1;

	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(centerIndex);
		meshData.Indices32.push_back(baseIndex + i+1);
		meshData.Indices32.push_back(baseIndex + i);
	}
}

void GeometryGenerator::BuildCylinderBottomCap(float bottomRadius, float topRadius, float height,
											   uint32 sliceCount, uint32 stackCount, MeshData& meshData)
{
	// 
	// Build bottom cap.
	//

	uint32 baseIndex = (uint32)meshData.Vertices.size();
	float y = -0.5f*height;

	// vertices of ring
	float dTheta = 2.0f*XM_PI/sliceCount;
	for(uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = bottomRadius*cosf(i*dTheta);
		float z = bottomRadius*sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x/height + 0.5f;
		float v = z/height + 0.5f;

		meshData.Vertices.push_back( Vertex(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v) );
	}

	// Cap center vertex.
	meshData.Vertices.push_back( Vertex(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f) );

	// Cache the index of center vertex.
	uint32 centerIndex = (uint32)meshData.Vertices.size()-1;

	for(uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.Indices32.push_back(centerIndex);
		meshData.Indices32.push_back(baseIndex + i);
		meshData.Indices32.push_back(baseIndex + i+1);
	}
}

GeometryGenerator::MeshData GeometryGenerator::CreateGrid(float width, float depth, uint32 m, uint32 n)
{
    MeshData meshData;

	uint32 vertexCount = m*n;
	uint32 faceCount   = (m-1)*(n-1)*2;

	//
	// Create the vertices.
	//

	float halfWidth = 0.5f*width;
	float halfDepth = 0.5f*depth;

	float dx = width / (n-1);
	float dz = depth / (m-1);

	float du = 1.0f / (n-1);
	float dv = 1.0f / (m-1);

	meshData.Vertices.resize(vertexCount);
	for(uint32 i = 0; i < m; ++i)
	{
		float z = halfDepth - i*dz;
		for(uint32 j = 0; j < n; ++j)
		{
			float x = -halfWidth + j*dx;

			meshData.Vertices[i*n+j].Position = XMFLOAT3(x, 0.0f, z);
			meshData.Vertices[i*n+j].Normal   = XMFLOAT3(0.0f, 1.0f, 0.0f);
			meshData.Vertices[i*n+j].TangentU = XMFLOAT3(1.0f, 0.0f, 0.0f);

			// Stretch texture over grid.
			meshData.Vertices[i*n+j].TexC.x = j*du;
			meshData.Vertices[i*n+j].TexC.y = i*dv;
		}
	}
 
    //
	// Create the indices.
	//

	meshData.Indices32.resize(faceCount*3); // 3 indices per face

	// Iterate over each quad and compute indices.
	uint32 k = 0;
	for(uint32 i = 0; i < m-1; ++i)
	{
		for(uint32 j = 0; j < n-1; ++j)
		{
			meshData.Indices32[k]   = i*n+j;
			meshData.Indices32[k+1] = i*n+j+1;
			meshData.Indices32[k+2] = (i+1)*n+j;

			meshData.Indices32[k+3] = (i+1)*n+j;
			meshData.Indices32[k+4] = i*n+j+1;
			meshData.Indices32[k+5] = (i+1)*n+j+1;

			k += 6; // next quad
		}
	}

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateQuad(float x, float y, float w, float h, float depth)
{
    MeshData meshData;

	meshData.Vertices.resize(4);
	meshData.Indices32.resize(6);

	// Position coordinates specified in NDC space.
	meshData.Vertices[0] = Vertex(
        x, y - h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f);

	meshData.Vertices[1] = Vertex(
		x, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f);

	meshData.Vertices[2] = Vertex(
		x+w, y, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f);

	meshData.Vertices[3] = Vertex(
		x+w, y-h, depth,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f);

	meshData.Indices32[0] = 0;
	meshData.Indices32[1] = 1;
	meshData.Indices32[2] = 2;

	meshData.Indices32[3] = 0;
	meshData.Indices32[4] = 2;
	meshData.Indices32[5] = 3;

    return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateCone(float radius, float height, uint32 sliceCount, uint32 stackCount)
{
	MeshData meshData;

	if (stackCount < 1 || stackCount > 20)
		stackCount = 20;

	//Creation of the bottom face of the cone
	meshData.Vertices.push_back(Vertex(0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f));
	float dTheta = 2.0f*XM_PI / sliceCount;
	float angle = 0.0f;
	for (uint32 j = 0; j < sliceCount; j++)
	{
		meshData.Vertices.push_back(Vertex(radius * cosf(angle), 0.0f, radius * sinf(angle), cosf(angle), 0.0f, sinf(angle), -sinf(angle), 0.0f, cosf(angle), 1.0f, 1.0f));
		angle += dTheta;
	}

	float dHeight = height / 20.0f;
	float currHeight = dHeight;
	float dRadius = radius / 20.0f;
	float currRadius = radius - dRadius;
	//Creates the ring for the cone
	for (uint32 i = 0; i < stackCount; i++)
	{
		angle = 0.0f;
		for (uint32 j = 0; j < sliceCount; j++)
		{
			meshData.Vertices.push_back(Vertex(currRadius * cosf(angle), currHeight, currRadius * sinf(angle), cosf(angle), 0.0f, sinf(angle), -sinf(angle), 0.0f, cosf(angle), 1.0f, 1.0f));
			angle += dTheta;
		}
		if (!(i == stackCount - 1) || (i == stackCount - 1 && i == 19))
			currHeight += dHeight;
		currRadius -= dRadius;
	}
	//Tip of top center
	meshData.Vertices.push_back(Vertex(0.0f, currHeight, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f));

	//Bottom Face
	for (uint32 i = 0; i < sliceCount; i++)
	{
		meshData.Indices32.push_back(0);
		meshData.Indices32.push_back(i + 1);
		if (i == sliceCount - 1)
			meshData.Indices32.push_back(1);
		else
			meshData.Indices32.push_back(i + 2);
	}
	//Side Face
	uint32 lowRingStart = 1;
	uint32 highRingStart = lowRingStart + sliceCount;
	for (uint32 i = 0; i < stackCount; i++)
	{
		for (uint32 j = 0; j < sliceCount; j++)
		{
			if (j == sliceCount - 1)
			{
				meshData.Indices32.push_back(lowRingStart + j);
				meshData.Indices32.push_back(highRingStart + j);
				meshData.Indices32.push_back(lowRingStart);

				meshData.Indices32.push_back(lowRingStart);
				meshData.Indices32.push_back(highRingStart + j);
				meshData.Indices32.push_back(highRingStart);
			}
			else
			{
				meshData.Indices32.push_back(lowRingStart + j);
				meshData.Indices32.push_back(highRingStart + j);
				meshData.Indices32.push_back(lowRingStart + j + 1);

				meshData.Indices32.push_back(lowRingStart + j + 1);
				meshData.Indices32.push_back(highRingStart + j);
				meshData.Indices32.push_back(highRingStart + j + 1);
			}

		}
		lowRingStart = highRingStart;
		highRingStart += sliceCount;
	}

	//Top Face
	uint32 last = (uint32)meshData.Vertices.size() - 1;
	for (uint32 i = 0; i < sliceCount; i++)
	{
		meshData.Indices32.push_back(last);
		if (i == sliceCount - 1)
			meshData.Indices32.push_back(lowRingStart);
		else
			meshData.Indices32.push_back(lowRingStart + i + 1);
		meshData.Indices32.push_back(lowRingStart + i);
	}

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateWedge(float width, float height, float length)
{
	MeshData meshData;

	meshData.Vertices.resize(6);
	meshData.Indices32.resize(24);

	//Initialization of the Vertices
	meshData.Vertices[0] = Vertex(0.0f, 0.0f, 0.0f, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[1] = Vertex(width, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[2] = Vertex(0.0, height, 0.0f, 0.0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[3] = Vertex(0.0f, 0.0f, length, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[4] = Vertex(width, 0.0f, length, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[5] = Vertex(0.0f, height, length, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	//Right face of the wedge
	meshData.Indices32[0] = 0;
	meshData.Indices32[1] = 1;
	meshData.Indices32[2] = 2;
	//Left face of the wedge
	meshData.Indices32[3] = 3;
	meshData.Indices32[4] = 4;
	meshData.Indices32[5] = 5;
	//Surrounding faces of the wedge
	meshData.Indices32[6] = 0;
	meshData.Indices32[7] = 3;
	meshData.Indices32[8] = 4;
	meshData.Indices32[9] = 0;
	meshData.Indices32[10] = 4;
	meshData.Indices32[11] = 1;
	meshData.Indices32[12] = 1;
	meshData.Indices32[13] = 4;
	meshData.Indices32[14] = 5;
	meshData.Indices32[15] = 1;
	meshData.Indices32[16] = 5;
	meshData.Indices32[17] = 2;
	meshData.Indices32[18] = 2;
	meshData.Indices32[19] = 5;
	meshData.Indices32[20] = 3;
	meshData.Indices32[21] = 2;
	meshData.Indices32[22] = 3;
	meshData.Indices32[23] = 0;

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateTorus(float largeRadius, float smallRadius, uint32 sliceCount, uint32 ringCount)
{
	MeshData meshData;

	float dTheta = 2.0f*XM_PI / sliceCount;
	float angleTheta = 0.0f;
	float dDelta = 2.0f*XM_PI / ringCount;
	float angleDelta = 0.0f;
	//Initializes the vertices to be used for the torus
	for (uint32 i = 0; i < ringCount; i++)
	{
		float centerX = largeRadius * cosf(angleDelta);
		float centerZ = largeRadius * sinf(angleDelta);
		for (uint32 j = 0; j < sliceCount; j++)
		{
			float ux = smallRadius * cosf(angleTheta) * centerX;
			float uz = smallRadius * cosf(angleTheta) * centerZ;
			float vy = smallRadius * sinf(angleTheta);
			meshData.Vertices.push_back(Vertex(centerX + ux, vy, centerZ + uz, ux, vy, uz, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
			angleTheta += dTheta;
		}
		angleDelta += dDelta;
	}

	int startRing = 0;
	int nextRing = 0 + sliceCount;
	//Takes the established vertices and uses them to create the torus
	for (uint32 i = 0; i < ringCount; i++)
	{
		for (uint32 j = 0; j < sliceCount; j++)
		{
			if (j == sliceCount - 1)
			{
				meshData.Indices32.push_back(startRing + j);
				meshData.Indices32.push_back(startRing);
				meshData.Indices32.push_back(nextRing + j);

				meshData.Indices32.push_back(startRing);
				meshData.Indices32.push_back(nextRing);
				meshData.Indices32.push_back(nextRing + j);

			}
			else
			{
				meshData.Indices32.push_back(startRing + j);
				meshData.Indices32.push_back(startRing + j + 1);
				meshData.Indices32.push_back(nextRing + j);

				meshData.Indices32.push_back(startRing + j + 1);
				meshData.Indices32.push_back(nextRing + j + 1);
				meshData.Indices32.push_back(nextRing + j);
			}
		}
		startRing = nextRing;
		nextRing += sliceCount;
		if (nextRing >= (uint32)meshData.Vertices.size())
			nextRing = 0;
	}

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreatePyramid(float width, float height, uint32 stackCount)
{
	MeshData meshData;

	if (stackCount < 1 || stackCount > 20)
		stackCount = 20;

	//Initialization for the bottom vertices of the pyramid
	meshData.Vertices.push_back(Vertex(width / 2, 0.0f, width / 2, cosf(XM_PI / 4), 0.0f, sinf(XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
	meshData.Vertices.push_back(Vertex(width / 2, 0.0f, -width / 2, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
	meshData.Vertices.push_back(Vertex(-width / 2, 0.0f, -width / 2, cosf(-3 * XM_PI / 4), 0.0f, sinf(-3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
	meshData.Vertices.push_back(Vertex(-width / 2, 0.0f, width / 2, cosf(3 * XM_PI / 4), 0.0f, sinf(3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

	float dWidth = width / 20.0f;
	float currWidth = width - dWidth;
	float dHeight = height / 20.0f;
	float currHeight = dHeight;
	//Initialization for the vertices of the sides of the pyramid
	for (uint32 i = 0; i < stackCount; i++)
	{
		meshData.Vertices.push_back(Vertex(currWidth / 2, currHeight, currWidth / 2, cosf(XM_PI / 4), 0.0f, sinf(XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		meshData.Vertices.push_back(Vertex(currWidth / 2, currHeight, -currWidth / 2, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		meshData.Vertices.push_back(Vertex(-currWidth / 2, currHeight, -currWidth / 2, cosf(-3 * XM_PI / 4), 0.0f, sinf(-3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		meshData.Vertices.push_back(Vertex(-currWidth / 2, currHeight, currWidth / 2, cosf(3 * XM_PI / 4), 0.0f, sinf(3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));
		currWidth -= dWidth;
		if (!(i == stackCount - 1) || (i == stackCount - 1 && i == 19))
			currHeight += dHeight;
	}
	meshData.Vertices.push_back(Vertex(0.0f, currHeight, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));


	//Bottom Face
	meshData.Indices32.push_back(0);
	meshData.Indices32.push_back(2);
	meshData.Indices32.push_back(1);
	meshData.Indices32.push_back(0);
	meshData.Indices32.push_back(3);
	meshData.Indices32.push_back(2);
	//Side Face
	uint32 lowSquareStart = 0;
	uint32 highSquareStart = lowSquareStart + 4;
	for (uint32 i = 0; i < stackCount; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j != 3)
			{
				meshData.Indices32.push_back(lowSquareStart + j);
				meshData.Indices32.push_back(lowSquareStart + j + 1);
				meshData.Indices32.push_back(highSquareStart + j);

				meshData.Indices32.push_back(lowSquareStart + j + 1);
				meshData.Indices32.push_back(highSquareStart + j + 1);
				meshData.Indices32.push_back(highSquareStart + j);
			}
			else
			{
				meshData.Indices32.push_back(lowSquareStart + j);
				meshData.Indices32.push_back(lowSquareStart);
				meshData.Indices32.push_back(highSquareStart + j);

				meshData.Indices32.push_back(lowSquareStart);
				meshData.Indices32.push_back(highSquareStart);
				meshData.Indices32.push_back(highSquareStart + j);
			}
		}
		lowSquareStart = highSquareStart;
		highSquareStart += 4;
	}

	//Top Face
	uint32 top = (uint32)meshData.Vertices.size() - 1;
	meshData.Indices32.push_back(top);
	meshData.Indices32.push_back(lowSquareStart);
	meshData.Indices32.push_back(lowSquareStart + 1);
	meshData.Indices32.push_back(top);
	meshData.Indices32.push_back(lowSquareStart + 1);
	meshData.Indices32.push_back(lowSquareStart + 2);
	meshData.Indices32.push_back(top);
	meshData.Indices32.push_back(lowSquareStart + 2);
	meshData.Indices32.push_back(lowSquareStart + 3);
	meshData.Indices32.push_back(top);
	meshData.Indices32.push_back(lowSquareStart + 3);
	meshData.Indices32.push_back(lowSquareStart);

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateDiamond(float height, float width)
{
	MeshData meshData;

	meshData.Vertices.resize(17);
	meshData.Indices32.resize(72);

	float midHeight = (2.0f / 3.0f) * height;
	float w45 = sqrtf(2.0f) / 2.0f * width;
	float topWidth = (2.0f / 3.0f) * width;
	float top45 = sqrtf(2.0f) / 2.0f * topWidth;
	float cx = 0.0f;
	float cy = height / 2.0f;
	float cz = 0.0f;

	//Initialization of the vertices to be used in the diamond
	meshData.Vertices[0] = Vertex(0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	meshData.Vertices[1] = Vertex(-width, midHeight, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	meshData.Vertices[8] = Vertex(-w45, midHeight, w45, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	meshData.Vertices[7] = Vertex(0.0f, midHeight, width, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[6] = Vertex(w45, midHeight, w45, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	meshData.Vertices[5] = Vertex(width, midHeight, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	meshData.Vertices[4] = Vertex(w45, midHeight, -w45, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	meshData.Vertices[3] = Vertex(0.0f, midHeight, -width, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[2] = Vertex(-w45, midHeight, -w45, -1.0f, 0.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	meshData.Vertices[9] = Vertex(-topWidth, height, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	meshData.Vertices[16] = Vertex(-top45, height, top45, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	meshData.Vertices[15] = Vertex(0.0f, height, topWidth, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	meshData.Vertices[14] = Vertex(top45, height, top45, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	meshData.Vertices[13] = Vertex(topWidth, height, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	meshData.Vertices[12] = Vertex(top45, height, -top45, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	meshData.Vertices[11] = Vertex(0.0f, height, -topWidth, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	meshData.Vertices[10] = Vertex(-top45, height, -top45, -1.0f, 0.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	//Bottom Faces
	meshData.Indices32[0] = 0;
	meshData.Indices32[1] = 1;
	meshData.Indices32[2] = 2;
	meshData.Indices32[3] = 0;
	meshData.Indices32[4] = 2;
	meshData.Indices32[5] = 3;
	meshData.Indices32[6] = 0;
	meshData.Indices32[7] = 3;
	meshData.Indices32[8] = 4;
	meshData.Indices32[9] = 0;
	meshData.Indices32[10] = 4;
	meshData.Indices32[11] = 5;
	meshData.Indices32[12] = 0;
	meshData.Indices32[13] = 5;
	meshData.Indices32[14] = 6;
	meshData.Indices32[15] = 0;
	meshData.Indices32[16] = 6;
	meshData.Indices32[17] = 7;
	meshData.Indices32[18] = 0;
	meshData.Indices32[19] = 7;
	meshData.Indices32[20] = 8;
	meshData.Indices32[21] = 0;
	meshData.Indices32[22] = 8;
	meshData.Indices32[23] = 1;

	//Top Faces
	meshData.Indices32[24] = 1;
	meshData.Indices32[25] = 9;
	meshData.Indices32[26] = 2;
	meshData.Indices32[27] = 9;
	meshData.Indices32[28] = 10;
	meshData.Indices32[29] = 2;
	meshData.Indices32[30] = 2;
	meshData.Indices32[31] = 10;
	meshData.Indices32[32] = 3;
	meshData.Indices32[33] = 10;
	meshData.Indices32[34] = 11;
	meshData.Indices32[35] = 3;
	meshData.Indices32[36] = 3;
	meshData.Indices32[37] = 11;
	meshData.Indices32[38] = 4;
	meshData.Indices32[39] = 11;
	meshData.Indices32[40] = 12;
	meshData.Indices32[41] = 4;
	meshData.Indices32[42] = 4;
	meshData.Indices32[43] = 12;
	meshData.Indices32[44] = 5;
	meshData.Indices32[45] = 12;
	meshData.Indices32[46] = 13;
	meshData.Indices32[47] = 5;
	meshData.Indices32[48] = 5;
	meshData.Indices32[49] = 13;
	meshData.Indices32[50] = 6;
	meshData.Indices32[51] = 13;
	meshData.Indices32[52] = 14;
	meshData.Indices32[53] = 6;
	meshData.Indices32[54] = 6;
	meshData.Indices32[55] = 14;
	meshData.Indices32[56] = 7;
	meshData.Indices32[57] = 14;
	meshData.Indices32[58] = 15;
	meshData.Indices32[59] = 7;
	meshData.Indices32[60] = 7;
	meshData.Indices32[61] = 15;
	meshData.Indices32[62] = 8;
	meshData.Indices32[63] = 15;
	meshData.Indices32[64] = 16;
	meshData.Indices32[65] = 8;
	meshData.Indices32[66] = 8;
	meshData.Indices32[67] = 16;
	meshData.Indices32[68] = 1;
	meshData.Indices32[69] = 16;
	meshData.Indices32[70] = 9;
	meshData.Indices32[71] = 1;

	return meshData;
}

GeometryGenerator::MeshData GeometryGenerator::CreateTriPrism(float triLength, float triHeight, float length)
{
	MeshData meshData;

	meshData.Vertices.resize(6);
	meshData.Indices32.resize(24);

	//Initialization of the verticies of the triangular prism
	meshData.Vertices[0] = Vertex(0.0f, 0.0f, 0.0f, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[1] = Vertex(triLength / 2, triHeight, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[2] = Vertex(triLength, 0.0f, 0.0f, cosf(-3 * XM_PI / 4), 0.0f, sinf(-3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[3] = Vertex(0.0f, 0.0f, length, cosf(-XM_PI / 4), 0.0f, sinf(-XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[4] = Vertex(triLength / 2, triHeight, length, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	meshData.Vertices[5] = Vertex(triLength, 0.0f, length, cosf(-3 * XM_PI / 4), 0.0f, sinf(-3 * XM_PI / 4), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	//Right face
	meshData.Indices32[0] = 0;
	meshData.Indices32[1] = 1;
	meshData.Indices32[2] = 2;
	//Left face
	meshData.Indices32[3] = 3;
	meshData.Indices32[4] = 4;
	meshData.Indices32[5] = 5;
	//Surrounding faces
	meshData.Indices32[6] = 0;
	meshData.Indices32[7] = 3;
	meshData.Indices32[8] = 4;
	meshData.Indices32[9] = 0;
	meshData.Indices32[10] = 4;
	meshData.Indices32[11] = 1;
	meshData.Indices32[12] = 1;
	meshData.Indices32[13] = 4;
	meshData.Indices32[14] = 5;
	meshData.Indices32[15] = 1;
	meshData.Indices32[16] = 5;
	meshData.Indices32[17] = 2;
	meshData.Indices32[18] = 2;
	meshData.Indices32[19] = 5;
	meshData.Indices32[20] = 3;
	meshData.Indices32[21] = 2;
	meshData.Indices32[22] = 3;
	meshData.Indices32[23] = 0;

	return meshData;
}