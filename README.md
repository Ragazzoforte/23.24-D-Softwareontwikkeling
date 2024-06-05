# 23.24-D-Softwareontwikkeling
jaar 23/24 periode D Software Ontwikkeling

# Project Description
The demo application follows the 3-Tier model and showcase the EE-API-LIB functions in the third layer. It will execute commands from a scripting language with the following structure:

Front Layer: Reads script commands.
Logic Layer: Contains drawing functionality.
I/O Layer: Manages input and output to the hardware.
By completing this project, We will deliver a fully operational solution with the EE-API-library and a client application, along with comprehensive documentation and professional source code. This will enable IP’s in-house programmers to gain practical experience with the new VGA screens.

## Team members
- Michel Vollmuller
- Tim Wannet
- Tijmen Willemsen

## Project workflow
- **Development Tools**: Visual Studio Code, GitHub and GitHub Desktop
- **Methodology**: Scrum with Github as scrum board. https://github.com/users/Ragazzoforte/projects/2/views/1
- **Communication Tools**: WhatsApp and GitHub.
- **Documentation Tools**: Doxygen and GitHub. https://ragazzoforte.github.io/23.24-D-Softwareontwikkeling/
- **Version Control**: GitHub
- **Coding Standards**: C++ Coding Standards

# Project rules

## Branches
From every issue, a new branch will be created. The branch name will be the same as the issue name. The branch will be merged into the main branch after the issue is completed. Every branch will be deleted after merging.

A Branch name should always start with the following prefixes:

- Feature Branches: feature/. 
- Bugfix Branches: bugfix/.
- Hotfix Branches: hotfix/.
- Release Branches: release/.
- Documentation Branches: docs/.

# Manual

## Graphical Design
Een grafisch overzicht met commentaar, met de lagen, functies en onderlinge samenhang.
![Local Image](image.jpg)

## 3-tier model
Beschrijving + onderbouwing van 3-lagenmodel.

## Scipts-commands
- lijn, x, y, x’, y’, kleur, dikte
- rechthoek, x_lup, y_lup, breedte, hoogte, kleur, gevuld (1,0) [als 1: rand (1px) met kleur]
- tekst, x, y, kleur, tekst, fontnaam (arial, consolas), fontgrootte (1,2), fontstijl (normaal,
vet, cursief)
- bitmap, nr, x-lup, y-lup [tenminste: pijl (in 4 richtingen), smiley (boos, blij)]
- clearscherm, kleur
- polygon, x, y, size, corner, kleur, reserved
- cirkel, x, y, radius, kleur, gevuld (1,0) [als 1: rand (1px) met kleur]


## Colours
zwart, blauw, lichtblauw, groen, lichtgroen, cyaan, lichtcyaan, rood, lichtrood, magenta,
lichtmagenta, bruin, geel, grijs, wit