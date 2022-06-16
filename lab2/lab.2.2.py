<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003" ToolsVersion="4.0">
  <PropertyGroup>
    <Configuration Condition=" '$(Configuration)' == '' ">Debug</Configuration>
    <SchemaVersion>2.0</SchemaVersion>
    <ProjectGuid>c073b808-7615-4a2a-93de-893681fb77ac</ProjectGuid>
    <ProjectHome>..\..\..\source\repos\lab.2.2.py\lab.2.2.py\</ProjectHome>
    <StartupFile>lab.2.2.py.py</StartupFile>
    <SearchPath>
    </SearchPath>
    <WorkingDirectory>.</WorkingDirectory>
    <OutputPath>.</OutputPath>
    <Name>lab.2.2</Name>
    <RootNamespace>lab.2.2.py</RootNamespace>
  </PropertyGroup>
  <PropertyGroup Condition=" '$(Configuration)' == 'Debug' ">
    <DebugSymbols>true</DebugSymbols>
    <EnableUnmanagedDebugging>false</EnableUnmanagedDebugging>
  </PropertyGroup>
  <PropertyGroup Condition=" '$(Configuration)' == 'Release' ">
    <DebugSymbols>true</DebugSymbols>
    <EnableUnmanagedDebugging>false</EnableUnmanagedDebugging>
  </PropertyGroup>
  <ItemGroup>
    <Compile Include="..\..\..\..\Documents\op2sem\лаб2\Classes.py">
      <SubType>Code</SubType>
      <Link>Classes.py</Link>
    </Compile>
    <Compile Include="lab.2.2.py.py" />
    <Compile Include="..\..\..\..\Documents\op2sem\лаб2\functions.py">
      <SubType>Code</SubType>
      <Link>functions.py</Link>
    </Compile>
  </ItemGroup>
  <Import Project="$(MSBuildExtensionsPath32)\Microsoft\VisualStudio\v$(VisualStudioVersion)\Python Tools\Microsoft.PythonTools.targets" />
  <!-- Uncomment the CoreCompile target to enable the Build command in
       Visual Studio and specify your pre- and post-build commands in
       the BeforeBuild and AfterBuild targets below. -->
  <!--<Target Name="CoreCompile" />-->
  <Target Name="BeforeBuild">
  </Target>
  <Target Name="AfterBuild">
  </Target>
</Project>