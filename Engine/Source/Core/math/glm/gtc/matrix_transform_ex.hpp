/// @ref gtc_matrix_transform
/// @file glm/gtc/matrix_transform.hpp
///
/// @see core (dependence)
/// @see gtx_transform
/// @see gtx_transform2
/// 
/// @defgroup gtc_matrix_transform GLM_GTC_matrix_transform
/// @ingroup gtc
///
/// @brief Defines functions that generate common transformation matrices.
///
/// The matrices generated by this extension use standard OpenGL fixed-function
/// conventions. For example, the lookAt function generates a transform from world
/// space into the specific eye space that the projective matrix functions 
/// (perspective, ortho, etc) are designed to expect. The OpenGL compatibility
/// specifications defines the particular layout of this eye space.
///
/// <glm/gtc/matrix_transform.hpp> need to be included to use these functionalities.

#pragma once

// Dependencies
#include "../mat4x4.hpp"
#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../gtc/constants.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_matrix_transform extension included")
#endif

namespace glm
{
	/// @addtogroup gtc_matrix_transform
	/// @{

	/// Builds a translation 4 * 4 matrix created from a vector of 3 components.
	/// 
	/// @param m Input matrix multiplied by this translation matrix.
	/// @param v Coordinates of a translation vector.
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @code
	/// #include <glm/glm.hpp>
	/// #include <glm/gtc/matrix_transform.hpp>
	/// ...
	/// Creates a matrix for an orthographic parallel viewing volume, using the default handedness.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param zNear
	/// @param zFar
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
		T left,
		T right,
		T bottom,
		T top,
		T zNear,
		T zFar,
		bool _oglNdc);

	/// Creates a matrix for an orthographic parallel viewing volume, using left-handedness.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param zNear
	/// @param zFar
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> orthoLH(
		T left,
		T right,
		T bottom,
		T top,
		T zNear,
		T zFar,
		bool _oglNdc);

	/// Creates a matrix for an orthographic parallel viewing volume, using right-handedness.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param zNear
	/// @param zFar
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> orthoRH(
		T left,
		T right,
		T bottom,
		T top,
		T zNear,
		T zFar,
		bool _oglNdc);

	/// Creates a matrix for projecting two-dimensional coordinates onto the screen.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	/// @see - glm::ortho(T const & left, T const & right, T const & bottom, T const & top, T const & zNear, T const & zFar)
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> ortho(
		T left,
		T right,
		T bottom,
		T top,
		bool _oglNdc);

	/// Creates a frustum matrix with default handedness.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param near
	/// @param far
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> frustum(
		T left,
		T right,
		T bottom,
		T top,
		T near,
		T far,
		bool _oglNdc);

	/// Creates a left handed frustum matrix.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param near
	/// @param far
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> frustumLH(
		T left,
		T right,
		T bottom,
		T top,
		T near,
		T far,
		bool _oglNdc);

	/// Creates a right handed frustum matrix.
	///
	/// @param left
	/// @param right
	/// @param bottom
	/// @param top
	/// @param near
	/// @param far
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> frustumRH(
		T left,
		T right,
		T bottom,
		T top,
		T near,
		T far,
		bool _oglNdc);

	/// Creates a matrix for a symetric perspective-view frustum based on the default handedness.
	/// 
	/// @param fovy Specifies the field of view angle in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspective(
		T fovy,
		T aspect,
		T near,
		T far,
		bool _oglNdc);

	/// Creates a matrix for a right handed, symetric perspective-view frustum.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveRH(
		T fovy,
		T aspect,
		T near,
		T far,
		bool _oglNdc);

	/// Creates a matrix for a left handed, symetric perspective-view frustum.
	/// 
	/// @param fovy Specifies the field of view angle, in degrees, in the y direction. Expressed in radians.
	/// @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveLH(
		T fovy,
		T aspect,
		T near,
		T far,
		bool _oglNdc);

	/// Builds a perspective projection matrix based on a field of view and the default handedness.
	/// 
	/// @param fov Expressed in radians.
	/// @param width 
	/// @param height 
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFov(
		T fov,
		T width,
		T height,
		T near,
		T far,
		bool _oglNdc);

	/// Builds a right handed perspective projection matrix based on a field of view.
	/// 
	/// @param fov Expressed in radians.
	/// @param width 
	/// @param height 
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFovRH(
		T fov,
		T width,
		T height,
		T near,
		T far,
		bool _oglNdc);

	/// Builds a left handed perspective projection matrix based on a field of view.
	/// 
	/// @param fov Expressed in radians.
	/// @param width 
	/// @param height 
	/// @param near Specifies the distance from the viewer to the near clipping plane (always positive).
	/// @param far Specifies the distance from the viewer to the far clipping plane (always positive).
	/// @tparam T Value type used to build the matrix. Currently supported: half (not recommanded), float or double.
	/// @see gtc_matrix_transform
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> perspectiveFovLH(
		T fov,
		T width,
		T height,
		T near,
		T far,
		bool _oglNdc);

	/// Map the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates.
	/// 
	/// @param obj Specify the object coordinates.
	/// @param model Specifies the current modelview matrix
	/// @param proj Specifies the current projection matrix
	/// @param viewport Specifies the current viewport
	/// @return Return the computed window coordinates.
	/// @tparam T Native type used for the computation. Currently supported: half (not recommanded), float or double.
	/// @tparam U Currently supported: Floating-point types and integer types.
	/// @see gtc_matrix_transform
	template <typename T, typename U, precision P>
	GLM_FUNC_DECL tvec3<T, P> project(
		tvec3<T, P> const & obj,
		tmat4x4<T, P> const & model,
		tmat4x4<T, P> const & proj,
		tvec4<U, P> const & viewport,
		bool _oglNdc);

	/// Map the specified window coordinates (win.x, win.y, win.z) into object coordinates.
	///
	/// @param win Specify the window coordinates to be mapped.
	/// @param model Specifies the modelview matrix
	/// @param proj Specifies the projection matrix
	/// @param viewport Specifies the viewport
	/// @return Returns the computed object coordinates.
	/// @tparam T Native type used for the computation. Currently supported: half (not recommanded), float or double.
	/// @tparam U Currently supported: Floating-point types and integer types.
	/// @see gtc_matrix_transform
	template <typename T, typename U, precision P>
	GLM_FUNC_DECL tvec3<T, P> unProject(
		tvec3<T, P> const & win,
		tmat4x4<T, P> const & model,
		tmat4x4<T, P> const & proj,
		tvec4<U, P> const & viewport,
		bool _oglNdc);

	/// @}
}//namespace glm

#include "matrix_transform_ex.inl"
