# LaTeX — Mathematical Typesetting (Termux + Neovim on Android)

**Platform:** Termux (Android) + proot-distro Debian + Neovim + pdflatex  
**Task:** Typeset CBSE and GATE problems using LaTeX mathematical notation  
**Toolchain:** `pdflatex` compiled inside Termux Debian; viewed with `termux-open`

## Why LaTeX Is Part This Internship

At FWC IITH, LaTeX is used for all technical documentation. Every platform's
GATE question solution is first written as a LaTeX document — demonstrating
both mathematical communication skills and toolchain proficiency.

## Workflow (entirely on Android phone)

```bash
proot-distro login debian
cd /sdcard/latex-project/
nvim integration.tex        # edit in Neovim
pdflatex integration.tex    # compile
termux-open integration.pdf # view PDF
```

## Three Problem Sets

### 1. Integration (`integration/`)
- Definite integrals with trigonometric functions
- Integrating factors of differential equations
- Area between curves using integration

### 2. Geometry (`geometry/`)
- 3D geometry (sphere, cone, cylinder volumes)
- Coordinate geometry and trigonometry
- Proof problems using similar triangles

### 3. GATE IN 2022 (`gate-in-2022/`)
- Digital circuits question (the core GATE problem solved across all platforms)
- LaTeX formatted with figure inclusion and solution derivation

## Build Instructions

```bash
# Inside Termux Debian:
cd latex/integration/src/
pdflatex integration.tex

cd ../geometry/src/
pdflatex geometry.tex

cd ../../gate-in-2022/src/
pdflatex gate_in_2022.tex
```

## LaTeX Key Commands Used

| Command | Purpose |
|---------|---------|
| `\begin{align}` | Numbered equation environment |
| `\int^{a}_{b}` | Definite integral |
| `\frac{dy}{dx}` | Fraction / derivative |
| `\tan^{-1}` | Inverse tangent |
| `\includegraphics` | Embed circuit diagram figures |
| `\begin{enumerate}` | Numbered MCQ options |

## Output Videos

- `gate_latex_nvim_full.mp4` — Neovim editing GATE LaTeX question
- `integration_latex_nvim_iith.mp4` — Integration problems typeset live
- `geometry_latex_nvim_iith.mp4` — Geometry problems typeset live

See [`../outputs/latex-recordings/`](../outputs/latex-recordings/)
