nonengine is a minimal PBR IBL engine descended from Panda3D. Usage is intended to be compatible with most existing Panda3D programs. nonengine is intended to work with [complexpbr](https://pypi.org/project/panda3d-complexpbr/) for PBR IBL real-time scene rendering.

## Sample Screenshots
<img width="1920" height="1080" alt="sponza_screen_1-Tue-Aug-04-05-18-16-2026-176" src="https://github.com/user-attachments/assets/98695c6c-4800-452e-8433-3752119d6862" />

<img width="2560" height="1440" alt="Time Dilation Lab nonengine screen 1a" src="https://github.com/user-attachments/assets/a35c7dac-7dfc-4206-b13d-80201d64209b" />

<img width="1920" height="1080" alt="Arcostudy screen 1a" src="https://github.com/user-attachments/assets/a00605fc-75eb-4ecb-88e0-b49b5e7c6946" />

## Permissive but NON-AI Policy
nonengine, starting Sep 29, 2023, does not allow usage for AI-training purposes or inclusion in an AI-dataset. nonengine is believed to be entirely free of generative AI contributions and does not accept PRs made with generative AI technology.

Other than that, you are free to do with nonengine as you like, including building commercial projects with it. See new_license.txt for details.

## Additional Engine Details
nonengine is roughly ~500,000 lines smaller than Panda3D. Many systems, including "tests", "distributed", and "PandAI" among many others have been carefully removed. The engine has been significantly refactored to support a leaner profile.

nonengine does not include any upstream Panda3D commits made since September 29th, 2023 .

## Installing with PyPI:
Currently, nonengine is a Linux-only wheel distribution.
```bash
pip install nonengine
```




