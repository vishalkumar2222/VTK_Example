
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2)

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderer.h>
#include <vtkOBJReader.h>
#include <vtkPNGReader.h>
#include <vtkTexture.h>
#include <vtkLight.h>

#include <vector>

int main(int, char* [])
{

	std::vector<std::string> obj_filenames = { "dependencies/media/bunny.obj", "dependencies/media/cube.obj", "dependencies/media/plane.obj" };
	std::vector<std::string> texture_filenames = { "dependencies/media/metal.png", "dependencies/media/crate.png", "dependencies/media/wood.png" };
	std::vector<std::vector<float>> translations = { {0, 0, 2}, {1, 1, 1}, {0, 0, 0} };
	std::vector<std::vector<float>> scales = { {7.0, 7.0, 7.0}, {0.5, 0.5, 0.5}, {10, 10, 10} };

	std::vector<vtkSmartPointer<vtkPolyData>> polydatas;
	std::vector<vtkSmartPointer<vtkTexture>> textures;

    for (auto&& obj_filename : obj_filenames) {
		vtkSmartPointer<vtkOBJReader> reader = vtkSmartPointer<vtkOBJReader>::New();
		reader->SetFileName(obj_filename.c_str());
		reader->Update();
		polydatas.push_back(reader->GetOutput());
    }

	for (auto&& filename : texture_filenames) {
		vtkSmartPointer<vtkPNGReader> reader = vtkSmartPointer<vtkPNGReader>::New();
		reader->SetFileName(filename.c_str());
		reader->Update();
		vtkSmartPointer<vtkTexture> texture = vtkSmartPointer<vtkTexture>::New();
		texture->SetInputConnection(reader->GetOutputPort());
		textures.push_back(texture);
	}
	
	if (polydatas.size() == 0) {
		std::cerr << "No polydatas loaded" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Loaded " << polydatas.size() << " polydatas" << std::endl;

    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(renderer);
    renWin->SetWindowName("GPU Renderer");

    vtkNew<vtkRenderWindowInteractor> iren;
    iren->SetRenderWindow(renWin);
    renderer->SetBackground(1.0, 1.0, 1.0); // Background color dark blue

	vtkSmartPointer< vtkInteractorStyleTrackballCamera> style = vtkSmartPointer< vtkInteractorStyleTrackballCamera>::New();
	iren->SetInteractorStyle(style);

	//vtkSmartPointer<vtkLight> pointLight = vtkSmartPointer<vtkLight>::New();
	//pointLight->SetFocalPoint(0, 0, 0);
	//pointLight->SetPosition(0, 0, 0);
	//pointLight->SetColor(1.0, 1.0, 1.0);
	//pointLight->SetIntensity(1.0);
	//renderer->AddLight(pointLight);

	for (size_t i = 0; i < polydatas.size(); i++) {

		vtkNew<vtkPolyDataMapper> mapper;
		mapper->SetInputData(polydatas[i]);

		// Create an actor
		vtkNew<vtkActor> actor;
		actor->SetMapper(mapper);
		actor->SetPosition(translations[i][0], translations[i][1], translations[i][2]);
		actor->SetScale(scales[i][0], scales[i][1], scales[i][2]);

		if (i < textures.size()) {
			actor->SetTexture(textures[i]);
		}
		renderer->AddActor(actor);
	}

    renderer->ResetCamera();
    renWin->SetSize(600, 600);

    // interact with data
    renWin->Render();
    iren->Start();

    return EXIT_SUCCESS;
}